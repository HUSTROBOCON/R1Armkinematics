# 思路

我们给定一个轨迹
得到了 由轨迹规划的 末端位置 速度 加速度
这些我们称为预期量

我们要得到关节相关的位置，速度，加速度

位置是直接读取当前的位置
速度是直接读取当前的速度

加速度分为两个部分 
一个是由预期速度，通过一个雅各比矩阵的式子求导后得到预期关节加速度
一个是由跟踪速度 ，和当前速度PID得到的加速度
跟踪速度则是由轨迹跟踪得到，轨迹跟踪是根据当前速度和下一个点的预期位置，或者还有预期速度联合求得

这样能得到一个加速度，再用雅各比求导得到关节加速度

最后输入动力学方程得到关节力矩

# 最后力矩的计算框架
1 .给定速度调节系数k,  得到轨迹， 规划出序列
2 .callback 得到当前机械臂的q ,dq
3 .根据序列计算出机械臂预期的关节速度和角度
4 .把预期速度，当前速度，位置 得到矫正的加速度
5. 把矫正加速度，轨迹规划的加速度 当前的机械臂的q ,dq输入到动力学方程中，得到关节力矩

# 重新思考了路线
我先给定角度来看单力矩能不能稳定，结果可以，证明力控是完全可以实现的。
接下来
首先依据是抄[参考blog](https://blog.csdn.net/qq_35231630/article/details/122174885)
说实话很像vmc
参考他的想法实现一个轨迹跟踪
轨迹规划的话，可以依据我之前那个，并且中间点用贝塞尔插值，反正点多多的
然后速度就用点的数量来控制，很像我之前的四足
当然也可以在动力学中加，这个也是一种思路

反正首先是先做轨迹跟踪，再做插值，最后来加入速度

思路1 两个p相加
$
\ddot{p} = \ddot{p}_{exp} + k_p(p_{exp} - p)+k_v(\dot{p}_{exp}-\dot{p})
$

跟踪效果，在低速且不规划力的时候误差较小，高速误差很大，几乎是无法接受的，而且速度难以产生较大影响
kp 2300 kv 60 

但是 kp 3000 kv 80 后段跟踪好 


我对末端加速度又加入了两层PID，跟踪效果大大提升，速度略有提升
核心代码
```
    Eigen::Vector3d nowPosition = forwardKinematics(qnow);
    Eigen::VectorXd nowVelocity = computeJacobian(qnow) * dqnow;
    
    

    Eigen::Vector2d nowPosition2d;
    nowPosition2d << nowPosition(0), nowPosition(2);
    Eigen::Vector2d nowVelocity2d;
    nowVelocity2d << nowVelocity(0), nowVelocity(2);
    Eigen::Vector3d ExpPosition = forwardKinematics(TestposExp.row(i00).cast<double>());

    //==== 方法1 ====
    // // 预期加速度 
    Eigen ::Vector3d inputAcc;
    inputAcc << 0, 0, 0;
    Eigen::Vector3d qExpI ;
    
    qExpI << TestposExp(i00, 0), TestposExp(i00, 1), TestposExp(i00, 2);
    Eigen::Vector3d dqExpI ;
    dqExpI << 0, 0, 0;

    // 结合一下方法二
    PID errorOuterPosPid(this->get_parameter("errposkp").as_double(), this->get_parameter("errposki").as_double(), this->get_parameter("errposkd").as_double(), this->get_parameter("errposoutlimit").as_double(), this->get_parameter("errposinterlimit").as_double(), 0.001);
    PID errorOuterVelPid(this->get_parameter("errvelkp").as_double(), this->get_parameter("errvelki").as_double(), this->get_parameter("errvelkd").as_double(), this->get_parameter("errveloutlimit").as_double(), this->get_parameter("errvelinterlimit").as_double(), 0.001);
    double angelTest = atan2(ExpPosition(2) - nowPosition(2), ExpPosition(0) - nowPosition(0));
    double inputanorm = errorOuterPosPid.PIDcalculate(ExpPosition.norm() - nowPosition.norm());
    double inputanormV = errorOuterVelPid.PIDcalculate((computeJacobian(qExpI) * dqExpI).norm() - nowVelocity.norm());
    inputAcc = computeJointAcceleration(Eigen::Vector3d(inputanormV * cos(angelTest), 0, inputanormV * sin(angelTest)), dqnow, qnow);
    
    inputAcc = inputAcc + arm_kp * (qExpI - qnow) + arm_kd * (dqExpI - dqnow);
    // RCLCPP_INFO(this->get_logger(), "inputAcc: %f, %f, %f", inputAcc(0), inputAcc(1), inputAcc(2));

    // 打印误差
    Eigen::Vector2d errorPos;
    errorPos(0) = forwardKinematics(qExpI)(0) - nowPosition(0);
    errorPos(1) = forwardKinematics(qExpI)(2) - nowPosition(2);
    if (i00 < 49)
    {RCLCPP_INFO(this->get_logger(), "errorPos: %f, %f", errorPos(0), errorPos(1));}

    Eigen::Matrix3d M = generateM(qnow);
    Eigen::Vector3d C = generateC(qnow, dqnow);
    Eigen::Vector3d G = generateG(qnow);
```

牢光建议 速度单环出加速度 位置只是提供加速度方向
然后 由count时序跟踪改成轨迹检测跟踪

经过赵学长的拷打，我发现了URDF存在方向问题，导致雅各比矩阵和动力学计算不适配，所以我修改了URDF，结果是有动力学跟踪的意思了，但是跟踪效果不太好

总结一下思路
主要思路是先对末端进行跟踪，这部分和我们路径规划是一样的，主要是速度和角速度PID跟踪。
只是在计算加速度转换为力矩的时候用到了动力学方程