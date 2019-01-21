//
//  inline_func.hpp
//  CppResearch
//
//  Created by BruceYoung on 2019/1/4.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#ifndef inline_func_hpp
#define inline_func_hpp

#include <stdio.h>
#include <iostream>
/*
 *宏，定义F(x) 为x+1这个函数,我们在使用的时候直接展开
 *而不是调用这个函数，调用函数会有额外的开销：参数压栈和
 *执行调用
 *但是宏的最大缺点就是不可控，可能会引入奇怪的bug
 */
#define F(x) (x+1)
#define PI 3.1415926

void useMacro();
/*
 *内联函数和宏的工作机制一样（代码插入展开），但是使用方法和普通函数一样，
 *这样一来，结合了宏和函数的优点，抛弃了宏和函数的缺点
 *因为是代码展开的方式，所以直接将定义写在头文件中
 */
inline void inlineFunc(){
    std::cout<<"inlineFunc"<<std::endl;
}


class InlineFuncDemo{
public:
    //直接写在类的内部的，编译器直接认为它是内联函数
    //但是注意，有些函数特别复杂的时候编译器，可能编译器不执行内联操作
    void inlineFunc(){
        std::cout<<"hello"<<std::endl;
    }
    //在外部定义的就不是内联函数了
    void notInline();
    //当然也可以将外部定义的函数主动声明为内联
    inline void forceInlineFunc();
    
    //访问器getter
    int getValue(){
        return value;
    }
    //修改器setter
    void setValue(int value){
        this->value = value;
    }
private:
    int value;
};

#endif /* inline_func_hpp */
