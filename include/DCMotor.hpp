#ifndef __DCMOTOR_H__
#define __DCMOTOR_H__

typedef enum DCMotorDriver
{
    L298N = 0,
    HG781,
    MDD10A
} DCMotorDriver;

class DCMotor
{
public:
    DCMotor(const int& pinA, const int& pinB, const float& MaxRPM, const int& pwmPin, DCMotorDriver& driver); // init motor pin mode
    void InitMotor();
    void GetVelocity(const float& vel);
    void Rotate();
    // void MotorInfo();
    ~DCMotor();

// private:
    DCMotorDriver driver_ = DCMotorDriver::L298N; // default is L298N
    float MaxVel_, Vel_;
    int pinA_, pinB_, pwmPin_;
    bool RotateDir_;
    float pwm_;

};

#endif