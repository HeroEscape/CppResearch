//
//  name_control.hpp
//  CppResearch
//
//  Created by BruceYoung on 2019/1/17.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#ifndef name_control_hpp
#define name_control_hpp

#include <stdio.h>
#include <iostream>
//1.函数内部的static变量
/*     栈内存
 * |———————————|staticValueFunc()
 * |  value=1  |
 * |    <------|---o              静态区
 * |           |   |    |————————————————————————|
 * |           |   o----|--->staticValue = 1     |
 * |           |        |                        |
 * |___________|        |________________________|
 *
 */
inline void staticValueFunc(){
    int value = 1;
    static int staticValue = 1;
    std::cout<<"value:"<<value<<std::endl;
    std::cout<<"staticValue:"<<staticValue<<std::endl;
    value++;
    staticValue++;
    
}
namespace name_control {
    class X{
        std::string name;
    public:
        X(std::string name):name(name){
            std::cout<<"name_control::X()=>"<<name<<std::endl;
        }
        ~X(){
            std::cout<<"name_control::~X()=>"<<name<<std::endl;
        }
        
    };
}

//2.函数内部的静态对象
inline void staticObj(){
    //普通对象
    name_control::X x("normal");
    
    //a.通过追踪构造函数可知，静态对象只会在第一次的时候被构造
    //普通对象每一次都会构建新的
    static name_control::X staticX("static");
    //b.析构函数调用的契机是咋main函数的结尾。
    //普通对象在退出函数的时候就会调用析构函数了
    
}


//3.连接控制
/*static这个东西在C++中b要比其他语言（比如Java）绕，它在不同上下文中表达者不同的意思
 *我们可以分为两种上下文，然后在两种情形下来掰持它的含义
 *情形一：在文件作用域-------------------->控制可见性
 *情形二：在内部作用域(类中/函数中)--------->控制存储位置
 *
 *然后我们来明确一件事情：                                ____________
 *在文件作用域中，不论一个变量/函数是不是static的，它都被存储到 |“静态数据区域”|
 *但是在内部作用域中的变量如果是static，那么就进入“静态数据区域”存储，而不是“堆和栈”
 *
 *总结：
 *在文件作用域中，static对应着extern(不可见/可见)
 *在内部作用域中，static是移动数据存储位置的关键字
 */
inline void linkControl(){
    
}

//4.命名空间namespace，类似于其他语言中的“包名”
//a.命名空间可以随拿随用，这一点区别于class和struct
namespace name_control_namespace_test {
    extern std::string slogon;
}
namespace name_control_namespace_test {
    extern std::string slogon4C;
}

//b.未命名空间
namespace {
    extern std::string noNameVlaue;
}


inline void nameControlMain(){
    //调用十次
    for(int i=0;i<10;i++){
        staticValueFunc();
        staticObj();
    }
    std::cout<<name_control_namespace_test::slogon<<std::endl;
    //std::cout<<name_control_namespace_test::slogon4C<<std::endl;
}
#endif /* name_control_hpp */
