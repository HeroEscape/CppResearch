//
//  struct_data.cpp
//  CppResearch
//
//  Created by BruceYoung on 2018/12/15.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include "struct_data.hpp"
#include <iostream>
using namespace std;
/*
 *struct 作为一种数据的封装，可以大大简化业务逻辑的抽象
 *比如一个汽车管理系统，一辆汽车作为一个业务对象，最好把这辆汽车的
 *各个数据都封装起来，否则会给代码编写带来巨大的混乱
 */
void previewStruct(){
    //一个简单的Car结构
    Car car;
    
    car.name = "QQ";
    car.price = 40000.00;
    car.type = 1;
    cout<<"car name:"<<car.name<<" price:"<<car.price<<" type:"<<car.type<<endl;
    
    //利用函数创建Car
    Car* car2 = createCar("QQ",40000.00,1);
    cout<<"car name:"<<car2->name<<" price:"<<car2->price<<" type:"<<car2->type<<endl;
    
}

Car* createCar(string name,float price,int type){
    //注意，必须用new 而不是 Car car，否则local变量在函数结束后自动销毁
    Car* car = new Car();
    car->name = name;
    car->price = price;
    car->type = type;
    return car;
    //wrong,不要用局部变量
//    Car car;
//    car.name = name;
//    car.price = price;
//    car.type = type;
//    return &car;
}

/*
 *c语言中用malloc和calloc来‘申请’内存
 *c++简化了这一个过程
 *用关键字new
 *         栈内存                    堆内存
 *  |————————————————|    ****************************
 *  |   函数入栈申请   |    *  int* ap = new int(10)   *
 *  |   int a = 10   |    * ———————————————————————— *
 *  |    _______     |    *      _______             *
 *  |    |栈内存 |    |    *      |堆内存 |            *
 *  |    |stack_|    |    *      |_heap_|            *
 *  |                |    * 如果没有delete ap，ap将常驻 *
 *  |    a自动释放     |    * 于堆内存中                 *
 *  |______出栈_______|    ****************************
 */
void dynamicMem(){
    //a存在于栈内存，随着函数的结束而自动释放
    int a = 10;
    //ap存在于堆内存，不会随着函数的结束而自动释放
    int* ap = new int(10);
    cout<<"a:"<<a<<" ap:"<<ap<<" *ap:"<<*ap<<endl;
    delete ap;
    
}

/*
 *普通数据可以作为结构体的成员，我们成为成员变量
 *函数也可以作为结构体的成员，我们称为成员函数
 *结构体的这种自我聚合数据能力（成员变量）+自我表达能力（成员函数）
 *使得我们的代码逻辑更加合理，逻辑更加紧凑，也更加贴近人的思维，加速了
 *程序开发的速度，这也是通向面向对象开发的基础
 */
void functionMember(){
    Car* car = createCar("BWM",400000,1);
    car->tellInfo();
}


void Car::tellInfo(){
    cout<<"car name:"<<name<<
    " price:"<<price<<
    " type:"<<this->type<<endl;
}

void Car::init(){
    fontLeftWheel = new Wheel();
    fontRightWheel = new Wheel();
    backLeftWheel = new Wheel();
    backRightWheel = new Wheel();
}
void Car::clear(){
    delete fontLeftWheel;
    delete fontRightWheel;
    delete backLeftWheel;
    delete backRightWheel;
}

void Car::start(){
    fontLeftWheel->run();
    fontRightWheel->run();
    backLeftWheel->run();
    backRightWheel->run();
}

/*
 *1.结构体的大小是结构体的“成员变量”的“和”
 *  |————记住只是成员变量，成员函数是不占用结构体空间的
 *  |————这个和不是线性的叠加，c++的对齐方式会让这个叠加变得复杂
 */
void objectMem(){
    Car car;
    cout<<"sizeof(car):"<<sizeof(Car)<<endl;
    
    struct A{
        char a;//1 byte
        double b;//8 bytes
        int c;// 4 bytes
        char d;//1 bytes
        //叠加的结果应该是1+8+4+1=14 bytes
    };
    cout<<"sizeof(A):"<<sizeof(A)<<endl;
    /* 但是这行代码显示sizeof(A)居然是24bytes
     *此处要说明一下c++结构体的内存对齐方式，
     *最重要的原则就是“整数倍原则”
     *
     *struct的成员变量在内存中紧密结合，一个一个的存放进入内存，但是每次存放
     *数据的时候，之前的内存空间必须是这一次存放数据的整数倍
     *
     *流程如下
     *char a
     *|1|
     
     *|     char a    |   double b    |
     *|B| | | | | | | |B|B|B|B|B|B|B|B|
     *  |__必须补齐7B___|
     *
     *当插入
     *double b的时候发现前面只有1B，而double是8B，所以前面的内存不是8B的
     *整数倍，所以必须补齐7B凑出8B的最小整数倍1*8B（补7B）
     *|     char a    |   double b    | intc  |
     *|B| | | | | | | |B|B|B|B|B|B|B|B|B|B|B|B|
     *int是4B前面是2*8=16B，是其整数倍，不需要补齐
     *
     *|     char a    |   double b    | int c |char d
     *|B| | | | | | | |B|B|B|B|B|B|B|B|B|B|B|B|B|
     *byte是1B前面是2*8+4=20B，是其整数倍，不需要补齐
     *
     *在补齐的情况下，现在是21bytes，然后剩下最后一个补齐g原则：
     *结构体的空间必须是其最大成员变量的整数倍
     *最大成员变量是double型的b，现在结构体的空间是21bytes，应该再补齐3B
     *变成24bytes，24是8的整数倍
     *|     char a    |   double b    | int c |char d
     *|B| | | | | | | |B|B|B|B|B|B|B|B|B|B|B|B|B| | | |
     *这样结果就是24B（24bytes）
     */
    
}

void Car::Wheel::run(){
    cout<<"wheel run"<<endl;
}

void carStart(){
    Car car;
    car.init();
    car.start();
    car.clear();
}


