#include "pid.hpp"
#include <algorithm> // for clamp

PID::PID(float _kp, float _ki, float _kd, float _output_limit, float _integrallimit, float _DT) :
    kp(_kp),
    ki(_ki),
    kd(_kd),
    DT(_DT),
    prev_error(0.0),
    integral(0.0)
{
    output_min = -fabs(_output_limit);
    output_max = fabs(_output_limit);
    integral_min = -fabs(_integrallimit);
    integral_max = fabs(_integrallimit);
}



float PID::PIDcalculate(float error) {
    integral += error * DT * ki;

    integral = std::clamp(integral, integral_min, integral_max);

    float derivative = (error - prev_error) / DT;
    float output = kp * error +  integral + kd * derivative;

    output = std::clamp(output, output_min, output_max);

    prev_error = error;
    return output;
}

float PID::PIDreset(){
    integral = 0.0;
    prev_error = 0.0;
}
