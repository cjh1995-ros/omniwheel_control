#include "EncoderDCMotor.hpp"
#include <ctime>
#include <iostream>

using namespace std;

EncoderMotor::EncoderMotor(const int& pinA, const int& pinB, const float& MaxRPM, const int& pwmPin, DCMotorDriver& driver, const int& encoderPin)
        :DCMotor(pinA, pinB, MaxRPM, pwmPin, driver), encoderPin_(encoderPin)
{}

EncoderMotor::~EncoderMotor(){}

void EncoderMotor::initMotor(const float& encoderCount)
{
    // pinMode(pinA_, OUTPUT);
    // pinMode(pinB_, OUTPUT);
    // pinMode(encoderPin_, OUTPUT);
    float MaxRPM = 5;
    cout<<"pinA is "<<pinA_<<endl;
    cout<<"pinB is "<<pinB_<<endl;
    cout<<"encoderPin is "<<encoderPin_<<endl;
    MaxVel_ = MaxRPM / (2*3.1415/60.0);
    encoderCount_ = encoderCount;
    prevTime = clock();
}

void EncoderMotor::GetRealVelocity(const float& tick_now)
{
    // tick to rad
    float rev, rad;
    clock_t curTime = clock();
    float diffTickCount = tick_now - prevTickCount;
    float diffTime = (float)(curTime - prevTime)/1000.0;
    rev = diffTickCount / encoderCount_;
    rad = rev/(2*3.1415);
    realVel_ = rad/diffTime;
    cout<<"real velocity is "<<realVel_<<endl;
    prevTime = curTime;
    prevTickCount = tick_now;
}

void EncoderMotor::CalcError()
{
    float err = realVel_ - Vel_;
    cout<<"error = "<<err<<endl;
}

void EncoderMotor::doPIDControl(){}
