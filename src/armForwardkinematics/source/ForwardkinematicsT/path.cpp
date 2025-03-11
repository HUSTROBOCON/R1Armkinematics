#include "ForwardkinematicsT/FT_method.hpp"

// 末端直线轨迹规划
Eigen::MatrixXd FT_method:: linepathPlan( int pathnum)
{
    Eigen::MatrixXd pathPoints(pathnum, 3);
    for (int i = 0; i < pathnum; i++)
    {
        pathPoints(i, 0) = init_pos(0) + cos( this->get_parameter("lineangle").as_double() * pi / 180) * i * this->get_parameter("linewidth").as_double() / pathnum;
        pathPoints(i, 1) = 0;
        pathPoints(i, 2) = init_pos(2) + sin( this->get_parameter("lineangle").as_double() * pi / 180) * i * this->get_parameter("linewidth").as_double() / pathnum;
        // pathPoints(i, 0) = init_pos(0);
        // pathPoints(i, 1) = 0;
        // pathPoints(i, 2) = init_pos(2);

    }

    return pathPoints;
}

// 末端速度轨迹规划
Eigen::MatrixXd FT_method:: linespeedpathPlan( int pathnum)
{
    Eigen::MatrixXd velPoints(pathnum , 2);
    double  v_cir = this->get_parameter("Vmax").as_double();
    for (int i = 0; i < pathnum; i++)
    {
        velPoints(i ,0) =  v_cir * (i + 20) * cos( this->get_parameter("lineangle").as_double() * pi / 180) / pathnum;
        velPoints(i ,1) =  v_cir + v_cir * (i + 20) * sin( this->get_parameter("lineangle").as_double() * pi / 180) / pathnum;
        // velPoints(i, 0) = 0;
        // velPoints(i, 1) = 0;
    
    }
    return velPoints;
}

// 末端角度规划
Eigen::VectorXd FT_method:: lineyawPlan( int pathnum)
{
    Eigen::VectorXd yawPoints(pathnum);
    double initial_yaw = initial_q(0) + initial_q(1) + initial_q(2);
    for (int i = 0; i < pathnum; i++)
    {
        yawPoints(i) = initial_yaw - (initial_yaw - this->get_parameter("shootangle").as_double() * pi / 180) * (i+10) / pathnum;
    }
    return yawPoints;   
}

// 末端角速度规划
Eigen::VectorXd FT_method:: linewristPlan( int pathnum)
{
    Eigen::VectorXd wristPoints(pathnum);
    for (int i = 0; i < pathnum; i++)
    {
        wristPoints(i) = this->get_parameter("Wmax").as_double();
    }
    return wristPoints;   
}