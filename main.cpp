#include <iostream>
#include "DCMotor.hpp"
#include "EncoderDCMotor.hpp"
#include <unistd.h>

int main(int, char**) {
    float vel = 0.0, maxvel = 5;
    int pa = 1, pb = 2, pwm =3, pe = 4;
    DCMotorDriver b = DCMotorDriver::L298N;
    DCMotor motor(pa,pb, maxvel, pwm, b);
    EncoderMotor encoder(pa,pb,maxvel, pwm, b, pe);
    encoder.initMotor(720);
    encoder.GetVelocity(2);
    sleep(2); // sec  
    encoder.GetRealVelocity(720);
    motor.GetVelocity(vel);
    motor.Rotate();

    return 0;
}
