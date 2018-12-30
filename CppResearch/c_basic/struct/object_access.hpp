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
 *3.行驶过程中不断的耗费油箱中的油，1km耗费1个单位的油
 *4.油箱最多可以装500单位的油
 *提示，用循环模拟行驶的路程，步进单位100m:
 *int distance = 0;
 *while(true){
 *  distance += 100;
 *  耗油
 *  if(distance%1000==0){//加油点
 *
 *  }
 *
 *}
 *
 *
 */
#endif /* object_access_hpp */
