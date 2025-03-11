#include "ForwardkinematicsT/FT_method.hpp"
#include <algorithm>

double Fn1(Eigen::Vector3d qi)
{
    return cos(qi(0)) * powf64(qi(1), 2) + sin(qi(0)) * qi(2);
}

double Fn2(Eigen::Vector3d qi)
{
    return -sin(qi(0)) * powf64(qi(1), 2) + cos(qi(0)) * qi(2);
}

double Fn3(Eigen::Vector3d qi)
{
    return cos(qi(0)) * qi(1);
}

double Fn4(Eigen::Vector3d qi)
{
    return -sin(qi(0)) * qi(1);
}


Eigen::Vector3d FT_method::zwzmcgcal(Eigen::Vector3d q, Eigen::Vector3d dq, Eigen::Vector3d ddq)
{
    Eigen::Vector3d q1(q(0), dq(0),  ddq(0));
    Eigen::Vector3d q2(q(1), dq(1),  ddq(1));
    Eigen::Vector3d q3(q(2), dq(2),  ddq(2));

    double y2 = L1 * sin(q1(0)) + Lc2 * sin(q1(0) + q2(0));
    double y3 = L1 * sin(q1(0)) + L2 * sin(q1(0) + q2(0)) + Lc3 * sin(q1(0) + q2(0) + q3(0));

    double dx2 = -L1 * sin(q1(0)) * q1(1) - Lc2 * sin(q1(0) + q2(0)) * (q1(1) + q2(1));
    double dy2 = L1 * cos(q1(0)) * q1(1) + Lc2 * cos(q1(0) + q2(0)) * (q1(1) + q2(1));

    double dx3 = -L1 * sin(q1(0)) * q1(1) - L2 * sin(q1(0) + q2(0)) * (q1(1) + q2(1)) - Lc3 * sin(q1(0) + q2(0) + q3(0)) * (q1(1) + q2(1) + q3(1));
    double dy3 = L1 * cos(q1(0)) * q1(1) + L2 * cos(q1(0) + q2(0)) * (q1(1) + q2(1)) + Lc3 * cos(q1(0) + q2(0) + q3(0)) * (q1(1) + q2(1) + q3(1));

    double ddx2 = -L1 * Fn1(q1) - Lc2 * Fn1(q1 + q2);
    double ddy2 = L1 * Fn2(q1) + Lc2 * Fn2(q1 + q2);

    double ddx3 = -L1 * Fn1(q1) - L2 * Fn1(q1 + q2) - Lc3 * Fn1(q1 + q2 + q3);
    double ddy3 = L1 * Fn2(q1) + L2 * Fn2(q1 + q2) + Lc3 * Fn2(q1 + q2 + q3);

    double dT1ddotq1 = m1 * Lc1 * q1(1) + Lc1 * q1(0) + J1 * q1(1);
    
    double ddotx2ddotq1 = -L1 * sin(q1(0)) - Lc2 * sin(q1(0) + q2(0));
    double ddoty2ddotq1 = L1 * cos(q1(0)) + Lc2 * cos(q1(0) + q2(0));
    
    double dT2ddotq1 = m2 * dx2 * ddotx2ddotq1 + m2 * dy2 * ddoty2ddotq1 + J2 * (q1(1) + q2(1));

    double ddotx3ddotq1 = -L1 * sin(q1(0)) - L2 * sin(q1(0) + q2(0)) - Lc3 * sin(q1(0) + q2(0) + q3(0));
    double ddoty3ddotq1 = L1 * cos(q1(0)) + L2 * cos(q1(0) + q2(0)) + Lc3 * cos(q1(0) + q2(0) + q3(0));

    double dT3ddotq1 = m3 * dx3 * ddotx3ddotq1 + m3 * dy3 * ddoty3ddotq1 + J3 * (q1(1) + q2(1) + q3(1));

    double ddtdT1ddotq1 = m1 * Lc1 * q1(2) + Lc1 * q1(1) + J1 * q1(2);

    double ddtddotx2ddotq1 = -L1 * cos(q1(0)) * q1(1) - Lc2 * cos(q1(0) + q2(0)) * (q1(1) + q2(1));
    double ddtddoty2ddotq1 = -L1 * sin(q1(0)) * q1(1) - Lc2 * sin(q1(0) + q2(0)) * (q1(1) + q2(1));
 
    double ddtdT2ddotq1 = m2 * ddx2 * ddotx2ddotq1 + m2 * dx2 * ddtddotx2ddotq1 + m2 * ddy2 * ddoty2ddotq1 + m2 * dy2 * ddtddoty2ddotq1 + J2 * (q1(2) + q2(2));

    double ddtddotx3ddotq1 = -L1 * Fn3(q1) - L2 * Fn3(q1 + q2) - Lc3 * Fn3(q1 + q2 + q3);
    double ddtddoty3ddotq1 = L1 * Fn4(q1) + L2 * Fn4(q1 + q2) + Lc3 * Fn4(q1 + q2 + q3);

    double ddtdT3ddotq1 = m3 * ddx3 * ddotx3ddotq1 + m3 * dx3 * ddtddotx3ddotq1 + m3 * ddy3 * ddoty3ddotq1 + m3 * dy3 * ddtddoty3ddotq1 + J3 * (q1(2) + q2(2) + q3(2));

    double dT1dq1 = 0;

    double ddotx2dq1 = -L1 * q1(1) * cos(q1(0)) - Lc2 * (q1(1) + q2(1)) * cos(q1(0) + q2(0));
    double ddoty2dq1 = L1 * Fn4(q1) + Lc2 * Fn4(q1 + q2);

    double dT2dq1 = m2 * (dx2 * ddotx2dq1 + dy2 * ddoty2dq1);
    
    double ddotx3dq1 = -L1 * Fn3(q1) - L2 * Fn3(q1 + q2) - Lc3 * Fn3(q1 + q2 + q3);
    double ddoty3dq1 = L1 * Fn4(q1) + L2 * Fn4(q1 + q2) + Lc3 * Fn4(q1 + q2 + q3);

    double dT3dq1 = m3 * (dx3 * ddotx3dq1 + dy3 * ddoty3dq1);

    double dU1dq1 = m1 * g * Lc1 * cos(q1(0));
    double dU2dq1 = m2 * g * (L1 * cos(q1(0)) + Lc2 * cos(q1(0) + q2(0)));
    double dU3dq1 = m3 * g * (L1 * cos(q1(0)) + L2 * cos(q1(0) + q2(0)) + Lc3 * cos(q1(0) + q2(0) + q3(0)));
    
    double tau1 = ddtdT1ddotq1 + ddtdT2ddotq1 + ddtdT3ddotq1 - dT1dq1 - dT2dq1 - dT3dq1 + dU1dq1 + dU2dq1 + dU3dq1;

    double dT1ddotq2 = 0;
    double ddtdT1ddotq2 = 0;

    double ddotx2ddotq2 = -Lc2 * sin(q1(0) + q2(0));
    double ddoty2ddotq2 = Lc2 * cos(q1(0) + q2(0));

    double dT2ddotq2 = m2 * (dx2 * ddotx2ddotq2 + dy2 * ddoty2ddotq2) + J2 * (q1(1) + q2(1));

    double ddtddotx2ddotq2 = -Lc2 * Fn3(q1 + q2);
    double ddtddoty2ddotq2 = Lc2 * Fn4(q1 + q2);

    double ddtdT2ddotq2 = m2 * (ddx2 * ddotx2ddotq2 + dx2 * ddtddotx2ddotq2 + ddy2 * ddoty2ddotq2 + dy2 * ddtddoty2ddotq2) + J2 * (q1(2) + q2(2));

    double dT1dq2 = 0;

    double ddotx2dq2 = -Lc2 * Fn3(q1 + q2);
    double ddoty2dq2 = Lc2 * Fn4(q1 + q2);

    double dT2dq2 = m2 * (dx2 * ddotx2dq2 + dy2 * ddoty2dq2);
    
    double ddotx3dq2 = -L2 * Fn3(q1 + q2) - Lc3 * Fn3(q1 + q2 + q3);
    double ddoty3dq2 = L2 * Fn4(q1 + q2) + Lc3 * Fn4(q1 + q2 + q3);

    double dT3dq2 = m3 * (dx3 * ddotx3dq2 + dy3 * ddoty3dq2);

    double dU1dq2 = 0;
    double dU2dq2 = m2 * g * Lc2 * cos(q1(0) + q2(0));
    double dU3dq2 = m3 * g * (L2 * cos(q1(0) + q2(0)) + Lc3 * cos(q1(0) + q2(0) + q3(0)));

    double ddotx3ddotq2 = -L2 * sin(q1(0) + q2(0)) - Lc3 * sin(q1(0) + q2(0) + q3(0));
    double ddoty3ddotq2 = L2 * cos(q1(0) + q2(0)) + Lc3 * cos(q1(0) + q2(0) + q3(0));

    double dT3ddotq2 = m3 * (dx3 * ddotx3ddotq2 + dy3 * ddoty3ddotq2) + J3 * (q1(1) + q2(1) + q3(1));

    double ddtdotx3ddotq2 = -L2 * Fn3(q1 + q2) - Lc3 * Fn3(q1 + q2 + q3);
    double ddtdoty3ddotq2 = L2 * Fn4(q1 + q2) + Lc3 * Fn4(q1 + q2 + q3);

    double ddtdT3ddotq2 = m3 * (ddx3 * ddotx3ddotq2 + dx3 * ddtdotx3ddotq2 + ddy3 * ddoty3ddotq2 + dy3 * ddtdoty3ddotq2) + J3 * (q1(2) + q2(2) + q3(2));

    double tau2 = ddtdT1ddotq2 + ddtdT2ddotq2 + ddtdT3ddotq2 - dT1dq2 - dT2dq2 - dT3dq2 + dU1dq2 + dU2dq2 + dU3dq2;

    double dT1ddotq3 = 0;
    double dT2ddotq3 = 0;

    double ddotx3ddotq3 = -Lc3 * sin(q1(0) + q2(0) + q3(0));
    double ddoty3ddotq3 = Lc3 * cos(q1(0) + q2(0) + q3(0));

    double dT3ddotq3 = m3 * (dx3 * ddotx3ddotq3 + dy3 * ddoty3ddotq3) + J3 * (q1(1) + q2(1) + q3(1));

    double ddtddotx3ddotq3 = -Lc3 * Fn3(q1 + q2 + q3);
    double ddtddoty3ddotq3 = Lc3 * Fn4(q1 + q2 + q3);

    double ddtdT3ddotq3 = m3 * (ddx3 * ddotx3ddotq3 + dx3 * ddtddotx3ddotq3 + ddy3 * ddoty3ddotq3 + dy3 * ddtddoty3ddotq3) + J3 * (q1(2) + q2(2) + q3(2));

    double ddotx3dq3 = -Lc3 * Fn3(q1 + q2 + q3);
    double ddoty3dq3 = Lc3 * Fn4(q1 + q2 + q3);

    double dT3dq3 = m3 * (dx3 * ddotx3dq3 + dy3 * ddoty3dq3);

    double dU1dq3 = 0;
    double dU2dq3 = 0;
    double dU3dq3 = m3 * g * Lc3 * cos(q1(0) + q2(0) + q3(0));

    double ddtdT1ddotq3 = 0;
    double ddtdT2ddotq3 = 0;

    double dT1dq3 = 0;
    double dT2dq3 = 0;

    double tau3 = ddtdT1ddotq3 + ddtdT2ddotq3 + ddtdT3ddotq3 - dT1dq3 - dT2dq3 - dT3dq3 + dU1dq3 + dU2dq3 + dU3dq3;

    tau1 = std::clamp(tau1, -20.0, 20.0);
    tau2 = std::clamp(tau2, -20.0, 20.0);
    tau3 = std::clamp(tau3, -20.0, 20.0);

    return Eigen::Vector3d(tau1, tau2, tau3);
}
