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
    
    /*
     *5.默认参数，比较简单，稍微了解一下，注意一下几点：
     *  |——只有参数的后半部分可以有默认参数
     *  |——一旦某个参数有默认值，后面的参数必须都要有默认值
     */
    void defaultParm(int a, int b=0);
    //wrong,编译不会通过
    //void defaultParm1(int a, int b=0, int c);
    /*
     *6.占位符参数
     */
    void occupiedParm(int a, int);
    /*
     *选择函数重载还是默认参数列表？
     *——如果你追求严谨和架构清晰：
     *能函数重载尽量函数重载，默认参数列表会导致一定的混乱，
     *虽然写起来很简单，很诱人，但是不是一个很好的编程习惯
     *比如后来的java语言，直接不支持函数的默认参数。
     *但是话分两头，
     *——如果你追求效率和简洁：
     *那就尽情使用默认参数列表好了，很多时候确实能加速我们的开发
     *而且代码也变得简洁
     */
}


#endif /* function_override_and_default_param_hpp */
