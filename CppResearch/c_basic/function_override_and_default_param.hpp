//
//  function_override_and_default_param.hpp
//  CppResearch
//
//  Created by BruceYoung on 2018/12/26.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#ifndef function_override_and_default_param_hpp
#define function_override_and_default_param_hpp

#include <stdio.h>
#include <iostream>
namespace function_override_and_default_parm {
    /*
     *1.函数重载：C语言函数名字是绝对不可以一样的，即使是函数的参数类型，个
     *数不一样，换句话说C语言不支持函数重载，但是C++支持
     *C++编译器会自动去区分这些函数，可能会生成新的名字（编译器如何去产生没
     *有统一的标准）
     */
    void func();//func()
    void func(int a);//func_int()
    void func(float a);//func_float()
    class X{
        void func();//X_func()
    };
    
    /*
     *2.按照返回值重载是不被允许的
     *int func();
     *因为在调用的时候不一定需要返回值：
     *int i = func()
     *可能是这样：
     *func()
     *这样一来就不知道调用的是那个版本的了
     */
    
    /*
     *3.C++可以避免C语言中的错误的函数声明推断
     */
    void funcWithoutDefine();
    
    /*
     *4.函数重载的一个重要用处：构造函数重载
     */
    class Phone{
        std::string band;
        float price;
        /*
         *多版本的构造函数
         */
    public:
        Phone();
        Phone(std::string band);
        Phone(float price);
        Phone(std::string band,float price);
        void log(){
            std::cout<<"band:"<<band<<" | price:"<<price<<std::endl;
        }
    };
    void multiConstructor();
}


#endif /* function_override_and_default_param_hpp */
