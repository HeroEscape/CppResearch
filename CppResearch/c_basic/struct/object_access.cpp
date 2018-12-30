//
//  object_access.cpp
//  CppResearch
//
//  Created by BruceYoung on 2018/12/19.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include "object_access.hpp"
#include <iostream>
using namespace std;
using namespace object_access;

void Car::tellInfo(){
    cout<<"car name:"<<name<<
    " price:"<<price<<
    " type:"<<this->type<<endl;

    cout<<"private member=>productionCosts:"<<productionCosts<<endl;
}
/*
 *使用Car的程序员不需要显式调用init函数，而是由构造函数调用，而构造函数
 *又是在对象创建的时候自动调用的
 */
Car::Car(){
    init();
}
/*
 *和构造函数一样，析构函数也是自动被调用，在对象被销毁的时候被调用
 */
Car::~Car(){
    clear();
}

void Car::init(){
    fontLeftWheel = new Wheel();
    fontRightWheel = new Wheel();
    backLeftWheel = new Wheel();
    backRightWheel = new Wheel();
    engine = new Engine();
    fuelTank = new FuelTank();
    versionName = "v1.0";
}
void Car::clear(){
    delete fontLeftWheel;
    delete fontRightWheel;
    delete backLeftWheel;
    delete backRightWheel;
    delete engine;
    delete fuelTank;
}

void Car::start(){
    engine->work();
    fontLeftWheel->run();
    fontRightWheel->run();
    backLeftWheel->run();
    backRightWheel->run();
}
void Car::Wheel::run(){
    cout<<"wheel run"<<endl;
}


void Car::Engine::work(){
    cout<<"Engine Working"<<endl;
}

void Car::selfClean(){
     cout<<"clean myself"<<endl;
}


/*
 *访问控制只在编译期间起作用，运行时和没有权限控制一样，如果我们真的尝试去访问
 *private成员，谁也无法阻拦我们，比如我们可以用指针去扫描访问数据。
 */
void object_access::objectMem(){
    Car* car = new Car();
    car->init();
    car->name = "Lamborghini";
    car->price = 20000000000;
    car->type = 1;
    //private 修饰的不可访问
    //car->versionName = "v1";
    
    char* p = reinterpret_cast<char*>(car);
    for(int i=0;i<sizeof(Car);i++){
        cout<<*p<<endl;
        p++;
    }
   


    delete car;
}


void object_access::jumpOverConstruct(){
    //在这里如果直接用goto跳过，那么Car的构造函数将被跳过这是不允许的
    //因为对象car在编译的时候已经分配了内存，但是初始化（构造函数）执行的
    //契机是在：Car car;这一句执行的时候，所以跳过会使得一个对象没有被初
    //始化
    //goto jump;
    Car car;
jump:
    cout<<"end"<<endl;
}
