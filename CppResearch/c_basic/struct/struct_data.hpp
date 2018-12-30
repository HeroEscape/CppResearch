//
//  struct_data.hpp
//  CppResearch
//
//  Created by BruceYoung on 2018/12/15.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#ifndef struct_data_hpp
#define struct_data_hpp

#include <stdio.h>
#include <string>
typedef struct Car{
    //成员变量
    std::string name;
    float price;
    int type;
    //成员函数
    void tellInfo();
    
    void init();
    void clear();
    void start();
    
    //5.嵌套结构体
    typedef struct Wheel{
        void run();
        
    } Wheel;
    //前左轮
    Wheel* fontLeftWheel;
    //前右轮
    Wheel* fontRightWheel;
    //后左轮
    Wheel* backLeftWheel;
    //后右轮
    Wheel* backRightWheel;
    
    
} Car;
//1.预览
void previewStruct();
Car* createCar(std::string name,float price,int type);
//2.动态内存分配
void dynamicMem();

//3.函数成员
void functionMember();

//4.对象的内存分布
void objectMem();

//6.一个初步面向对象的汽车系统
void carStart();
#endif /* struct_data_hpp */
