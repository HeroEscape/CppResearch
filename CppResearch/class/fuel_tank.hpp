//
//  fuel_tank.hpp
//  CppResearch
//
//  Created by BruceYoung on 2018/12/25.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#ifndef fuel_tank_hpp
#define fuel_tank_hpp

#include <stdio.h>
/*
 *class 里的成员默认时private的，要对外暴露需要用public修饰
 *struct 中的成员默认时public的
 *这是class和struct的最大的，也是唯一的区别。
 */
class FuelTank{
    float gasolineValue;
    float width;
    float height;
    float length;
public:
    void gasolineUp(float value){
        gasolineValue += value;
    }
    void useGasoline(float value){
        gasolineValue -= value;
    }
    float getGasOlineValue(){
        return gasolineValue;
    }
};
#endif /* fuel_tank_hpp */
