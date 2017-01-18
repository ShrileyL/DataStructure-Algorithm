//
//  Version of class Fan that aggregates ElectricMotor
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

class Fan
{
public:
    Fan(){};
    ~Fan(){};
    
    void StartFan(){m_electric.StarMotor();}
    
    void StopFan(){m_electric.StopMotor();}
    
private:
    ElectricMotor m_electric;
};

int main(int argc, char const *argv[])
{
    Fan mFan;
    
    mFan.StartFan();
    mFan.StopFan();
    return 0;
}

//******* Output *******
// Motor Started.
// Motor running at constant speed.
// Motor Stopped.