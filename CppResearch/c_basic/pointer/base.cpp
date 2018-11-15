//
//  base.cpp
//  CppResearch
//
//  Created by BruceYoung on 11/15/18.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include "base.hpp"
#include <iostream>
using namespace std;
void pointer(){
    int a=1;
    int b=2;
    int c=3;
    cout<<"&a=>"<<&a<<endl;
    cout<<"&b=>"<<&b<<endl;
    cout<<"&c=>"<<&c<<endl;
    cout<<"\n"<<endl;
    
    //int d = a 但是存储在不同的地方
    int d = a;
    cout<<"&a=>"<<&a<<endl;
    cout<<"&d=>"<<&d<<endl;
    cout<<"\n"<<endl;
    
    int* pa=&a;
    int* pb=&b;
    int* pc=&c;
    cout<<"*****指针变量的值*******"<<endl;
    cout<<"pa=>"<<pa<<endl;
    cout<<"pb=>"<<pb<<endl;
    cout<<"pc=>"<<pc<<endl;
    cout<<"\n"<<endl;
    
    cout<<"*****指针变量的值所指向的地址的值*******"<<endl;
    cout<<"*pa=>"<<*pa<<endl;
    cout<<"*pb=>"<<*pb<<endl;
    cout<<"*pc=>"<<*pc<<endl;
    cout<<"\n"<<endl;
    
    pa=&b;
    cout<<"*****after pa=&b*******"<<endl;
    cout<<"pa=>"<<pa<<endl;
    cout<<"*pa=>"<<*pa<<endl;
    cout<<"\n"<<endl;
    
    //a=b相当于把b的再内存中的值直接塞到a的内存中
    a = b;
    cout<<"******after a=b******"<<endl;
    cout<<"&a=>"<<&a<<endl;
    cout<<"&b=>"<<&b<<endl;
    cout<<"&d=>"<<&d<<endl;
    cout<<"a=>"<<a<<endl;
    cout<<"b=>"<<b<<endl;
    cout<<"d=>"<<d<<endl;
    cout<<"\n"<<endl;
}
void pointerWithNew(){
    int* pa= new int(1);
    int* pb= new int(2);
    int* pc= new int(3);
    cout<<"pa=>"<<pa<<endl;
    int a = *pa;
    int b = *pb;
    int c = *pc;
    cout<<"&a=>"<<&a<<endl;
    cout<<"&b=>"<<&b<<endl;
    cout<<"&c=>"<<&c<<endl;
    cout<<"\n"<<endl;
    
    //int* d = pa 存储在相同的地方
    int* pd = pa;
    int d = *pd;
    cout<<"&a=>"<<&a<<endl;
    cout<<"&d=>"<<&d<<endl;
    cout<<"\n"<<endl;
    
    
    cout<<"*****指针变量的值*******"<<endl;
    cout<<"pa=>"<<pa<<endl;
    cout<<"pb=>"<<pb<<endl;
    cout<<"pc=>"<<pc<<endl;
    cout<<"\n"<<endl;
    
    cout<<"*****指针变量的值所指向的地址的值*******"<<endl;
    cout<<"*pa=>"<<*pa<<endl;
    cout<<"*pb=>"<<*pb<<endl;
    cout<<"*pc=>"<<*pc<<endl;
    cout<<"\n"<<endl;
    
    pa=&b;
    cout<<"*****after pa=&b*******"<<endl;
    cout<<"pa=>"<<pa<<endl;
    cout<<"*pa=>"<<*pa<<endl;
    cout<<"\n"<<endl;
    
    //a=b相当于把b的再内存中的值直接塞到a的内存中
    a = b;
    cout<<"******after a=b******"<<endl;
    cout<<"&a=>"<<&a<<endl;
    cout<<"&b=>"<<&b<<endl;
    cout<<"&d=>"<<&d<<endl;
    cout<<"a=>"<<a<<endl;
    cout<<"b=>"<<b<<endl;
    cout<<"d=>"<<d<<endl;
    cout<<"\n"<<endl;
}

/*
 *按值传递
 */
void funcNeedVariable(int variable){
    cout<<"&variable=>"<<&variable<<endl;
    cout<<"variable=>"<<variable<<endl;
    variable++;
}

/*
 *按指针传递
 */
void funcNeedPointer(int* pointer){
    cout<<"pointer=>"<<pointer<<endl;
    cout<<"*pointer=>"<<*pointer<<endl;
    (*pointer) ++;
}

void funcValueTrans(){
    int a = 1;
    cout<<"&a=>"<<&a<<endl;
    cout<<"\n"<<endl;
    cout<<"before funcNeedVariable a=>"<<a<<endl;
    funcNeedVariable(a);
    cout<<"after funcNeedVariable a=>"<<a<<endl;
    //按值传递会开辟新的内存变量
    
    cout<<"\n"<<endl;
    cout<<"before funcNeedPointer a=>"<<a<<endl;
    funcNeedPointer(&a);
    cout<<"after funcNeedPointer a=>"<<a<<endl;
    //按指针传递不会开辟新的内存变量
}

void pointerOfPointer(){
    int a =1;
    int* p = &a;
    cout<<p<<endl;
    
    int** pp = &p;
    cout<<pp<<endl;
    
    int*** ppp = &pp;
    cout<<ppp<<endl;
    
    
    int**** pppp = &ppp;
    cout<<pppp<<endl;
    
    
    int***** ppppp = &pppp;
    cout<<ppppp<<endl;
    
    cout<<*****ppppp<<endl;
    
    //指针的类型
    int b = 2;
    int* pb = &b;
    pb = p;//right
    //pb = pp;//wrong
    pb = *pp;//right
    cout<<pb<<endl;
    
    
}






