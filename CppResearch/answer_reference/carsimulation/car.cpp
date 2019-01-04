//
//  car.cpp
//  CppResearch
//
//  Created by BruceYoung on 2018/12/30.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include "car.hpp"
#include <iostream>
using namespace std;
car_simulation::Car::Car(){
    fontLeftWheel = new Wheel();
    fontRightWheel = new Wheel();
    backLeftWheel = new Wheel();
    backRightWheel = new Wheel();
    fuelTank = new FuelTank();
}

void car_simulation::Car::start(){
    cout<<"car start"<<endl;
    
}



void car_simulation::Car::stop(){
    fontLeftWheel->stop();
    fontRightWheel->stop();
    backLeftWheel->stop();
    backRightWheel->stop();
}
void car_simulation::Car::run(){
    fontLeftWheel->run();
    fontRightWheel->run();
    backLeftWheel->run();
    backRightWheel->run();
    fuelTank->useGasoline(1);
    cout<<"car current gas:"<<fuelTank->getGasOlineValue()<<endl;
    
}
