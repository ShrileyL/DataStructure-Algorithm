//
//  Demostration of private inheritance
//
//  Created by KevinLiu on 16/10/27.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
using namespace std;

class ElectricMotor
{
public:
	ElectricMotor(){};
	virtual ~ElectricMotor(){};

public:
	void StarMotor()
	{
		Accelerate();
		Cruise();
	}

	void StopMotor(){cout << "Motor Stopped." << endl;}
private:
	void Accelerate(){cout << "Motor Started." << endl;}
	void Cruise(){cout << "Motor running at constant speed." << endl;}
};

class Fan:private ElectricMotor
{
public:
	Fan();
	~Fan();
	
	void StartFan(){StarMotor();}

	void StopFan(){StopMotor();}
};

int main(int argc, char const *argv[])
{
	Fan mFan;

	mFan.StartFan();
	mFan.StopFan();

	// the next two lines access the base class ElectricMotor
	// however, as Fan features "private inheritance" from ElectricMotor,
	// neuther the base class instance nor its public methods
	// are acessible to the user of class Fan
	// un-comment them to see a complie fauilture!

	// mFan.Accelerate();
	// ElectricMotor * pMotor = &mFan;
	return 0;
}

//******* Output *******
// Motor Started.
// Motor running at constant speed.
// Motor Stopped.
