#include<stdio.h>



class Motor {
public:
	virtual void SetOutput() = 0;
	virtual int Getspeed() = 0;
	virtual float Update() = 0;
	virtual ~Motor() {};
};

class DJMotor:public Motor {
public:
	void SetOutput()override{
		printf("[CAN BUS] ID: 0x201, Send Current : 500");
	}
	int Getspeed()override {
		return 1000 ;
	}
	float Update() { return 0; }
};

class SimMotor :public Motor {
	double velocity_;
	void SetOutput() {}
	int Getspeed() { return 0; }
public:
	float Update()override {
		float Inputforce=0, resistance=0;
		velocity_ = velocity_ + (Inputforce - resistance);
		return velocity_;
	}
	
};

void TestMotor(Motor* motor) {
	motor->SetOutput();
	motor->Update();
	motor->Getspeed();
	
}