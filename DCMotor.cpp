#include "DCMotor.hpp"
#include <iostream>

#ifdef _ARDUINO_H_
  #include "Arduino.h"
#endif
using namespace std;

DCMotor::DCMotor(const int &pinA, const int &pinB, const float &MaxRPM, const int  &pwmPin, DCMotorDriver& driver):
    pinA_(pinA), pinB_(pinB), pwmPin_(pwmPin), driver_(driver)
{
    // pinMode(pinA_, OUTPUT);
    // pinMode(pinB_, OUTPUT);
    cout<<"pinA is "<<pinA_<<endl;
    cout<<"pinB is "<<pinB_<<endl;
    MaxVel_ = MaxRPM / (2*3.1415/60.0);
}

DCMotor::~DCMotor(){}

void DCMotor::InitMotor()
{
    // pinMode(pinA_, OUTPUT);
    // pinMode(pinB_, OUTPUT);
    cout<<"init motor"<<endl;
}

void DCMotor::GetVelocity(const float& vel)
{
    Vel_ = vel;
    cout<<"get velocity = "<<Vel_<<endl;
    pwm_ = Vel_ / MaxVel_ * 255;
    RotateDir_ = Vel_ > 0 ? true : false;
}

void DCMotor::Rotate()
{
    switch(driver_)
    {
    case DCMotorDriver::L298N :
        if (RotateDir_)
        {
            // digitalWrite(pinA_, HIGH);
            // digitalWrite(pinB_, LOW);
            // analogWrite(pwmPin_, pwm_);
            cout<<"rotate dir is +"<<endl;
            cout<<"pwm = "<<pwm_<<endl;
        }
        else
        {
            // digitalWrite(pinA_, LOW);
            // digitalWrite(pinB_, HIGH);
            // analogWrite(pwmPin_, pwm_);
            cout<<"rotate dir is -"<<endl;
            cout<<"pwm = "<<pwm_<<endl;
        }
        break;
    };
}
