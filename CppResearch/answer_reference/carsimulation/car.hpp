//
//  car.hpp
//  CppResearch
//
//  Created by BruceYoung on 2018/12/30.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#ifndef car_hpp
#define car_hpp

#include <stdio.h>
#include "Wheel.hpp"
#include "../../class/fuel_tank.hpp"
namespace car_simulation{

    class Car{
    public:
        Car();
        ~Car();
        void start();
        void stop();
        void run();
        bool needAddGas(){
            if(this->fuelTank->getGasOlineValue()<10){
                return true;
            }else{
                return false;
            }
        }
        void addGas(int value){
            fuelTank->gasolineUp(value);
        }
        
        
    private:
        //前左轮
        Wheel* fontLeftWheel;
        //前右轮
        Wheel* fontRightWheel;
        //后左轮
        Wheel* backLeftWheel;
        //后右轮
        Wheel* backRightWheel;
        FuelTank* fuelTank;
    };

}

#endif /* car_hpp */
