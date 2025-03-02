#ifndef PID_HPP
#define PID_HPP

#include <cmath>

class PID {
public:
    PID(float _kp, float _ki, float _kd,float _output_limit,float _integral_limit, float _DT );
    float PIDcalculate(float error);
    float PIDreset();

private:
    float kp, ki, kd;
    float DT;
    float output_min, output_max;
    float integral_max, integral_min;
    float prev_error;
    float integral;
};


#endif