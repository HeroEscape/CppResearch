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
        
        std::string getName(){
            return name;
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
    void multiFunc();
}
namespace name_control_namespace_test {
    extern std::string slogon4C;
    void multiFunc();
}

namespace name_control_namespace_test2 {
    void multiFunc();
}

//b.未命名空间,可以把一个全局变量变成内连接的
namespace {
    std::string noNameVlaue="noNameVlaue";
}

//c.使用命名空间
//如果每一次都用 命名空间::变量/类的方式去引用，显得太过麻烦，我们可以使用using来简化这个过程
//但是建议不要（b或者是不能够）在头文件中用using，因为每个include这个头文件的地方相当于都using那个命名空间了
//这样会造成程序潜在的bug
void usingNameSpace();

//5.类中的static变量

namespace name_control {
    //我们现在有个需求：统计这个类有多少个实例？
    class Y{
    public:
        Y(){
            instanceCount++;
            std::cout<<"Y() instanceCount:"<<instanceCount<<std::endl;
        }
        ~Y(){
            instanceCount--;
            std::cout<<"~Y() instanceCount:"<<instanceCount<<std::endl;
        }
        
    public:
        //a.static全局共享，但是又被限定在了该类的作用域中
        //即q同一个类以及由该类产生的示例共享
        static int instanceCount;
        
        //b.这句代码无法编译通过，因为static的变量必须在外部（.cpp文件中）定义
        //static int hello=10;
        //这句代码也无法编译通过，和普通变量一样，自定义类型static变量也需要在外部定义
        //static X x("MyName");
        static X x;
        
        //c.静态函数
        static void staticFunc();
        
        //课堂练习
        //现在有一个要求：一个类只能被实例化一次，利用所学的知识点你怎么设计？
        //即经典的设计模式——单例模式
        
    };
}

inline void nameControlMain(){
    //调用十次
    for(int i=0;i<10;i++){
        staticValueFunc();
        staticObj();
    }
    std::cout<<name_control_namespace_test::slogon<<std::endl;
    std::cout<<name_control_namespace_test::slogon4C<<std::endl;
    std::cout<<"noNameVlaue:"<<noNameVlaue<<std::endl;
    
    usingNameSpace();
    
    for(int i=0;i<5;i++){
        name_control::Y y;
    }
    std::cout<<"Y::instanceCount=>"<<name_control::Y::instanceCount<<std::endl;
    
    //如果是new Y()，又会怎样呢？
    
    //静态对象
    std::cout<<"Y::x=>"<<name_control::Y::x.getName()<<std::endl;
    
    //静态函数
    name_control::Y::staticFunc();
    
   
}
#endif /* name_control_hpp */
