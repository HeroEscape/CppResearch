//
//  virtual_function.hpp
//  CppResearch
//
//  Created by BruceYoung on 2019/3/7.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#ifndef virtual_function_hpp
#define virtual_function_hpp

#include <stdio.h>
#include <iostream>
/*
 *概述：多态和虚函数是OOP编程中最核心的一个，也是OOP课程的最后一课，同时也是理解起来最花时间的一个
 *之前说到OOP的两个特点，总结一下
 *1.封装：源自于C中的结构体（struct），在C++中进化成class，把同一个事物抽象并封装到一起
 *2.继承：一个类的“能力”可以被他的子类继承去，使得程序拥有极大的复用性
 *今天要说的是第三点
 *3.多态：“同一个类”可以表现出不同的行为状态（注意“同一个类”加了引号），使得程序拥有极大的扩展性
 */
class Pet{
private:
    std::string name;
public:
    void speak(){
        std::cout<<"Pet speak"<<std::endl;
    }
    virtual void walk(){
        std::cout<<"Pet walk"<<std::endl;
    }
};

class Dog:public Pet{
public:
    Dog(){
        std::cout<<"Dog()"<<std::endl;
    }
    void speak(){
        std::cout<<"Dog speak"<<std::endl;
    }
    void walk(){
        std::cout<<"Dog walk"<<std::endl;
    }
};
inline void test(Pet* pet){
    /*
     * 此处调用的是哪个类的函数？
     */
    pet->speak();
    pet->walk();
    /*
     *1.早捆绑和晚捆绑
     *早捆绑：和C一样，编译和运行都是同一个类型，即对象定义的的样子，比如Pet* pet，那么pet就是
     *      一个确定的Pet类型了，不论传递进来的是Dog还是Pet，在编译时期都按照Pet处理了，运行的
     *      时候也只会是Pet而不会是Dog
     *Pet* pet = new Dog();
     *Pet* pet2 = new Cat();
     
     *晚捆绑：和其他比如java，python一样，有一句口诀叫“编译看左，运行看右”
     *      编译的时候按照定义的时候处理，但是在运行的时候动态的安装它本来的类型处理
     *  引起晚捆绑的方式就是virtual关键字
     *2.详解：C++如何实现晚捆绑？
     *vptr（虚指针）：每个对象有且仅有一个vptr
     *vtable（虚表）：每个包含virtual函数的类有且仅有一个vtable，用来存储各个函数的地址
     *                                       vtable
     *    Pet                   _______>|--------------|
     *|-----------|            /        |__&Pet::speak_|
     *|  vptr-----|-----------/         |__&Pet::walk__|
     *|___________|                     |_____...._____|
     *
     *    Dog                   _______>|--------------|
     *|-----------|            /        |__&Pet::speak_|
     *|  vptr-----|-----------/         |__&Dog::walk__|
     *|___________|                     |_____...._____|
     *
     *vptr指向speak，（vptr+一个指针的长度）指向walk函数
     *
     *为什么需要虚函数？
     *实际上晚捆绑是OOP编程的本质，应该是嵌入到语言内部的，是默认的行为，比如java等后出的
     *OOP的语言就是这么做的，没有虚函数着么一说，语言默认的都是晚捆绑的行为
     *C++的考虑来自于效率，运行时的虚函数执行不仅仅是函数压栈，还有vtable的寻找，虽然效率很高
     *但是C++作为一个把效率看的很重的语言，它需要显式的制定晚捆绑机制（virtual函数）
     */
}

inline void virtual_funtion_test(){
    Dog dog;
    test(&dog);
    
    
}

#endif /* virtual_function_hpp */
