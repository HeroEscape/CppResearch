//
//  grammar_homework.cpp
//  CppResearch
//
//  Created by BruceYoung on 2018/12/6.
//  Copyright © 2018 BruceYoung. All rights reserved.
//
#include "grammar_homework.hpp"
#include <iostream>
using namespace std;
void* (*f1(int))[10]{
    void* b[10] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    void*(*p)[10] = &b;
    cout<<"void* (*f1(int))[10]"<<endl;
    return p;
}
    
float f2f(int){
    cout<<"f2f(int)"<<endl;
    return 1.0;
}
float ((*f2(int,int,float))(int)){
    cout<<"float ((*f2(int,int,float))(int))"<<endl;
    return &f2f;
}

double f3f(){
    return 2.0;
}
//void* (*f3())[10]{
double (*(*f3())[10])(){
    //double(*b)()= &f3f;
    
    //double(*(*b)[10])();
    //b = new
    double(*b[10])() = { &f3f, &f3f, &f3f, &f3f, &f3f, &f3f, &f3f, &f3f, &f3f, &f3f };
    double (*(*p)[10])() = &b;
    cout<<"double (*(*f3())[10])()"<<endl;
    return p;
}
