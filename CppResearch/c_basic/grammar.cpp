//
//  grammar.cpp
//  CppResearch
//
//  Created by BruceYoung on 11/29/18.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include "grammar.hpp"
#include <iostream>
#include "../utils/util.hpp"
#include "../answer_reference/grammar_homework.hpp"
using namespace std;
/*
 *                  value=2
 *                     |
 *  |--------|         |
 *  |___0____|         |jump
 *  |___1____|         |
 *  |___2____|<--------|
 *  |___3____| |\__________break_____->
 *  |___4____| |
 *             |继续执行
 *             |
 *             v
 *如果switch没有break的话，所有的分支都要走
 */
void switchBreak(int value){
    switch (value) {
        case 0:{
            cout<<"value is 0"<<endl;
        }
        case 1:{
           cout<<"value is 1"<<endl;
        }
        case 2:{
            cout<<"value is 2"<<endl;
        }
        case 3:{
            cout<<"value is 3"<<endl;
        }
        default:{
            cout<<"value is thers"<<endl;

        }
            
    }
}

/*
 *goto很厉害，但是也很危险，容易造成程序的混乱，作为异种骨后备的trick，不能当作日常用法
 */
void badGoto(){
    for(int i=0;i<100;i++){
        cout<<"i:"<<i<<endl;
        for(int j=0;j<100;j++){
            cout<<"j:"<<j<<endl;
            if(j>10){
                break;
                //goto bottom;
            }
        }
    }
bottom:
    cout<<"end"<<endl;
}

void sign(){
    unsigned char i = -1;
    cout<<"i:"<<int(i)<<endl;
    char j = -1;
    cout<<"j:"<<int(j)<<endl;
}

void variableChange(){
    int a = 0;
    static int sa = 0;
    cout<<"a:"<<a<<endl;
    cout<<"sa:"<<sa<<endl;
    a++;
    sa++;
}

void staticVariable(){
    for(int i=0;i<10;i++){
        variableChange();
    }
}


extern int thirdpart_value;
//static value can not be linked from outter
//extern int thirdpart_static_value;
void useExtern(){
    cout<<"thirdpart_value:"<<thirdpart_value<<endl;
    // static value can not be linked from outter
    //cout<<thirdpart_static_value<<endl;
}


#define PI 3.14
void useConst(){
    cout<<"PI:"<<PI<<endl;
    const int pi = 110;
    //read only
    cout<<"pi:"<<pi<<endl;
    //常量不可改变值
    //pi = 4;
    
    
    const int* ppi = &pi;
    cout<<"ppi:"<<ppi<<endl;
    //read only
    cout<<"*ppi:"<<*ppi<<endl;
    //指向常量的指针也无法改变常量的值
    //*ppi=5;
    
    //常量转换const_cast

    int& rvi =const_cast<int&>(pi);
    int* pvi =const_cast<int*>(ppi);
    cout<<"pvi:"<<pvi<<endl;
    rvi = 2;
    cout<<"after const_cast<int&> pi:"<<pi<<endl;
    *pvi = 3;
    cout<<"*pvi:"<<*pvi<<endl;
    cout<<"after const_cast<int*> pi:"<<pi<<endl;
    
    /*问题来了，ppi和pvi是指向同一地址的指针，为什么同一个地址的数据会出现不同的值？
     *试试把const int pi = 110;改成
     *volatile const int pi = 110;
     *volatile 暗示编译器不要针对常量就行寄存器缓存优化，而是每一次在程序读取的时候都重新从内存中读取数据。
     */
    
    /*
     总结：c++并不能从根本上杜绝对const变量的修改，但是这种修改是显式的，编程者需要自己对这种“不恰当的行为”负责
     */
}

void binaryOpreation(){
    
    //按位操作
    cout<<"2&1:"<<(2&1)<<endl;
    cout<<"2|1:"<<(2|1)<<endl;
    cout<<"2^1:"<<(2^1)<<endl;
    
    int a = 1;
    cout<<"a<<1:"<<(a<<1)<<endl;
    cout<<"a<<2:"<<(a<<2)<<endl;
    //移位不会改变原始值，而是生成新的值
    printBinary(a<<8);

    int b = 1;
    cout<<"b>>1:"<<(b>>1)<<endl;
    cout<<"b>>2:"<<(b>>2)<<endl;
    
}

void func1(){
    cout<<"func1"<<endl;
}
void func2(){
    cout<<"func2"<<endl;
}
void func3(){
    cout<<"func3"<<endl;
}

/*
 *函数和变量一样，最终都要落实到计算机中的一块内存中，有内存，就有内存地址，有内存地址就有指针表达，所以
 *函数也是有指针的
 */
void functionAddress(int funcIndex){
    void(*funcPtr)();
    switch (funcIndex) {
        case 1:
            funcPtr = &func1;
            break;
        case 2:
            funcPtr = &func2;
            break;
        case 3:
            funcPtr = &func3;
            break;
            
        default:
            funcPtr = &func1;
            break;
    }
    
     (*funcPtr)();
    
    /*
     *think in c++上的说明的复杂定义的函数指针
     */
    void*(*(*p1)(int))[10];
    float (*(*p2)(int,int,float))(int);
    double (*(*(*p3)())[10])();
    
    //f4 是函数定义不是指针变量定义
    int (*(*f4())[10])();
}


/*
 *作业：
 *分别实现
 void*(*(*p1)(int))[10];
 float (*(*p2)(int,int,float))(int);
 double (*(*(*p3)())[10])();
 定义的函数
 *
 */


void homework(){
    void*(*(*p1)(int))[10] = &f1;
    (*p1)(10);
    float (*(*p2)(int,int,float))(int) = &f2;
    (*p2)(10,11,12);
    double (*(*(*p3)())[10])() = &f3;
    (*p3)();
}
