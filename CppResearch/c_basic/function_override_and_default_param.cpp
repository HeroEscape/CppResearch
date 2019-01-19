//
//  function_override_and_default_param.cpp
//  CppResearch
//
//  Created by BruceYoung on 2018/12/26.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include "function_override_and_default_param.hpp"
#include <iostream>
extern "C" {
#include "../c/c_demo.h"
}

using namespace std;
void function_override_and_default_parm::func(){
    cout<<"func()"<<endl;
}
void function_override_and_default_parm::func(int){
    cout<<"func(int)"<<endl;
}
void function_override_and_default_parm::func(float){
    cout<<"func(float)"<<endl;
}
void function_override_and_default_parm::X::func(){
    cout<<"X::func()"<<endl;
}
void function_override_and_default_parm::funcWithoutDefine(){
    
    //C中编译并不会报错，但是连接报错了
    //callFuncWithoutDefine();//in c
    
    //C++在你调用一个未申明的函数的时候编译直接报错
    //hello();
}
function_override_and_default_parm::Phone::Phone(){

}
function_override_and_default_parm::Phone::Phone(string band){
    this->band = band;
}
function_override_and_default_parm::Phone::Phone(float price){
    this->price = price;
}
function_override_and_default_parm::Phone::Phone(string band, float price){
    this->band = band;
    this->price = price;
}
//void function_override_and_default_parm::Phone::log(){
//    std::cout<<"band:"<<band<<"price:"<<price<<std::endl;
//}

void function_override_and_default_parm::multiConstructor(){
    Phone* p1 = new Phone();
    p1->log();
    Phone* p2 = new Phone("iPhone");
    p2->log();
    Phone* p3 = new Phone(2000);
    p3->log();
    Phone* p4 = new Phone("HUAWEI",2500);
    p4->log();
}

void function_override_and_default_parm::defaultParm(int a,int b){
    cout<<"a:"<<a<<endl;
    cout<<"b:"<<b<<endl;
}

void function_override_and_default_parm::occupiedParm(int a, int){
    
}
