//
//  copy_constructor.hpp
//  CppResearch
//
//  Created by BruceYoung on 2019/1/23.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#ifndef copy_constructor_hpp
#define copy_constructor_hpp

#include <stdio.h>
#include <iostream>
namespace copy_constructor{
    class X{
        int a;
        int b;
        
    public:
        X(){
            a=1;
            b=2;
            std::cout<<"create X and call X()"<<std::endl;
        }
        //拷贝构造函数
        //一个特殊的构造函数，当对象被‘拷贝’的时候被调用
        //我们会发现，a和b在定义了这个函数后并不等于1和2，
        //因为没有调用默认的X()
        //如果我们不自定义构造函数，编译器会帮我们创建一个默认的拷贝构造函数
        //默认的拷贝构造函数的行为是按位拷贝。
        X(const X& x){
            std::cout<<"create X and call X(X& x)"<<std::endl;
            a=3;
            b=4;
        }
        
        void log(){
            std::cout<<"a:"<<a<<" b:"<<b<<std::endl;
        }
    };
    
    /*
     *1.对象三种传递方式
     */
    
    //a.案值传递
    void func(X x);
    X funcWithValue4Return();
    //b.案指针传递
    void func(X* x);
    X* funcWithPointer4Return();
    //c.案引用传递
    void funcWithRef(X& x);
    X& functionWithRef4Return();
   
    
    
    //2.如何防止对象拷贝？
    
    
    inline void copyConstructorTest(){
        //我们看一下3中方式的区别
        //问题1.对象s被新建了吗
        std::cout<<"************** function params ****************"<<std::endl;
        X x;
        func(x);//新创建了
        func(&x);//没有新建
        funcWithRef(x);//没有新建
        //在按值传递的时候构造函数为什么没有调用？
        //因为使用了拷贝构造函数
        
        std::cout<<"**************** return value *****************"<<std::endl;
        //关于返回值
        funcWithValue4Return().log();
        funcWithPointer4Return()->log();
       
        
        functionWithRef4Return().log();
    }
}




#endif /* copy_constructor_hpp */
