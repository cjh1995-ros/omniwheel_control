#ifndef __ENCODER_DCMOTOR_H__
#define __ENCODER_DCMOTOR_H__
#include "DCMotor.hpp"

class EncoderMotor: public DCMotor
{
public:
    EncoderMotor(const int& pinA, const int& pinB, const float& MaxRPM, const int& pwmPin, DCMotorDriver& driver, const int& encoderPin);
    // : DCMotor(pinA, pinB, MaxRPM, pwmPin, driver), encoderPin_(encoderPin)
    void initMotor(const float& encoderCount);
    void GetRealVelocity(const float& tick_now);
    void CalcError();
    void doPIDControl();
    ~EncoderMotor();
private:
    int encoderPin_;
    float prevTickCount=0;
    float prevTime;
    float encoderCount_; // mine is 720 -> 1rev is 720 -> 
    float realVel_;
};
#endif