//
//  object_access.hpp
//  CppResearch
//
//  Created by BruceYoung on 2018/12/19.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#ifndef object_access_hpp
#define object_access_hpp

#include <stdio.h>
#include <string>
#include "../../class/fuel_tank.hpp"
namespace object_access{
typedef struct Car{
    /**
     *一个对象的初始化和清除靠的是构造函数和析构函数
     */
    //4.构造函数
    Car();
    //5.析构函数
    ~Car();
    /*
     *问题：有了构造函数和析构函数来自动调用init和clear函数后如果init
     *和clear函数还是public的，会产生什么隐患？
     *
     */
public:
    std::string name;
private:
    std::string versionName;
public:
    float price;
    int type;

    void tellInfo();
    void init();
    void clear();
    void start();

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
    typedef struct Engine{
        void work();

    } Engine;

//1.隐藏实现
private:
    int productionCosts;//生产成本
    Engine* engine;//引擎
    void selfClean();//自我清理
    //3.class
    FuelTank* fuelTank;
} Car;
//2.对象的内存分布
void objectMem();
    
//6.跳过c构造函数
void jumpOverConstruct();
//7.默认构造函数
}

/*
 *homework：
 *一个汽车仿真系统，功能：
 *1.可以发动：引擎启动->四个车轮各自工作
 *2.可以停止：引擎启动关闭->四个车轮停止
 *3.行驶过程中不断的耗费油箱中的油，1km耗费0.01L个单位的油,1L的油8元
 *4.油箱最多可以装50单位的油
 *5.在车油箱少于5单位的时候去加油（加油的时候熄火），加油需要5秒
 *仿真效果：
    北京到上海1200KM，仿真从北京行驶到上海的汽车耗油，消费情况
 
 *提示(伪代码)，用循环模拟行驶的路程，步进单位1000m:
 *int distance = 0;
 *while(true){
 *  distance += 1000;
 *  计算耗油量，并从油箱中取出油
 *
 *  if(fuleTank->getGasolineValue()<=5){//加油点
 *      car->gasUp();
 *  }
 *  
 *
 *}
 *
 *
 */
#endif /* object_access_hpp */
