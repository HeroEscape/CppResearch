//
//  base.cpp
//  CppResearch
//
//  Created by BruceYoung on 11/15/18.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include "pointer.hpp"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*
 *  -----------------0x7fff5fbff59c <------------|
 *  |               |                   ---------|---------|
 *  |   int a=1     |                   |  int* pa=&a      |
 *  |_______________|0x7fff5fbff598     |  0x7fff5fbff59c  |
 *  |               |                   |    pointer       |
 *  |   int b=2     |                   |__________________|
 *  |_______________|
 *
 *指针本身我们也可以看做是一个变量配合不同的数据类型，组合出不同的"指针型变量";
 *比如:
 *int* long* float*
 *....
 *普通变量（比如int a,long b,float c等），在内存中的特性，指针都有(地址，值，类型)，所以指针又称作"指针变量"
 *试着把(int*)看做一个整体，你就明白“指针也是一种变量”的含义了
 */
void pointerSummary(){
    int a=1,b=2,c=3;
    int* pa;
    int* pb;
    cout<<"&a=>"<<&a<<endl;
    cout<<"&b=>"<<&b<<endl;
    cout<<"&c=>"<<&c<<endl;
    cout<<"\n"<<endl;
    
    
    
}

/*
 *1.指针的长度是固定的，在不同位数的操作系统上表现不一样，32位上的是32位(4 byte)，64位上的是64位(8 byte)
 *2.不同类型的数据占用的空间是不同的，但是它们的指针的长度仍然是固定的
 */
void pointerSize(){
    int i = 10;
    int* pi = &i;
     cout<<"int* point size:"<<sizeof(pi)<<"=>int size:"<<sizeof(*pi)<<endl;
    
    char c = 97;
    char* pc = &c;
    cout<<"char* point size:"<<sizeof(pc)<<"=>char size:"<<sizeof(*pc)<<endl;
    
    long l = 97;
    long* pl = &l;
    cout<<"long* point size:"<<sizeof(pl)<<"=>long size:"<<sizeof(*pl)<<endl;
    
  
    float f = 97.0;
    float* pf = &f;
    cout<<"float* point size:"<<sizeof(pf)<<"=>float size:"<<sizeof(*pf)<<endl;
    
    double d = 97.0;
    double* pd = &d;
    cout<<"double* point size:"<<sizeof(pd)<<"=>double size:"<<sizeof(*pd)<<endl;
    
    bool b = true;
    bool* pb = &b;
    cout<<"bool* point size:"<<sizeof(pb)<<"=>bool size:"<<sizeof(*pb)<<endl;
}


void pointerOperation(){
    /*
     *1.指针的加减法可以看作是内存地址的“滑动”
     *int 类型的指针增加的步进电单位是4byte
     *long 类型的指针增加的步进电单位是8byte
     *....
     */
    int i = 100;
    int* pi = &i;
    cout<<"pi:"<<pi<<endl;
    cout<<"pi++"<<++pi<<endl;
    cout<<"pi--"<<--pi<<endl;
    
    long l = 100;
    long* pl = &l;
    cout<<"pl:"<<pl<<endl;
    cout<<"pl++:"<<++pl<<endl;
    cout<<"pl++:"<<--pl<<endl;
    
    
    /*
    *2.指针和指针相减表示两个指针所指的内存间隔几个byte
     */
    int i2 = 213;
    cout<<"pi-pi2:"<<(pi-&i2)<<endl;
}

void pointerMemory(){
    int a=1;
    int b=2;
    int c=3;
    
    // d 和 a的值一样 但是存储在不同的地方
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

/*
 *按引用传递
 */
void funcNeedRef(int& ref){
    cout<<"&ref=>"<<&ref<<endl;
    cout<<"ref=>"<<ref<<endl;
    ref++;
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
    
    cout<<"\n"<<endl;
    cout<<"before funcNeedRef a=>"<<a<<endl;
    funcNeedRef(a);
    cout<<"after funcNeedRef a=>"<<a<<endl;
    //按引用传递不会开辟新的内存变量
}

/**
 *由此印证了指针和普通变量的一致性
 */
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

void memoryScan(){
   
    int oneMB = 1024*1024;
    int oneGB = 1024*1024*1024;
    int* array = new int[oneGB];
    array[oneMB*100]=1024;
    int* p = &array[0];
    for(int i=0;i<1024;i++){
        cout<<"mem address:"<<p<<" mem data:"<<*p<<" scaned size:"<<i<<"MB"<<endl;
        p+=oneMB;
    }
    
}

void memoryFinder(){
    
    
    int memSize = 1024*1024*128;
    
    srand(time(NULL));
    int r = rand()%memSize;
     cout<<"rand:"<<r<<endl;
    
    int* array = new int[memSize];
    array[r]=1024;
    
    int* p = &array[0];
    for(int i=0;i<memSize;i++){
        //cout<<"current pos:"<<i<<endl;
        if(*p==1024){
            cout<<"mem address:"<<p<<" mem data:"<<*p<<" scaned size:"<<(i*4/1024)<<"KB"<<endl;
            break;
        }
        p++;
    }
    
}






