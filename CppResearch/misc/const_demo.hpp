//
// lesson 11:const(常量)
//  const_demo.hpp
//  CppResearch
//
//  Created by BruceYoung on 2019/1/7.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#ifndef const_demo_hpp
#define const_demo_hpp

#include <stdio.h>
#include <iostream>
/*
 *1.为何引进常量
 *在c语言中我们一般用宏来表示一个常量
 *用宏表示常量有几个问题：
 *a.没有类型检查，可能会引起无法预料的错误
 *b.由于宏的工作原理是预处理器直接替换，所以无法跟踪调试
 */
#define PI 3.14
const int BUFFER_SIZE = 3;
const int BUFFER_SIZES[] = {3,4,5};


//2.常量采用内部连接
//不可以
//普通变量采用外部连接，定义在头文件中，每个引用的源文件（.cpp文件）都会重新定义一遍，
//并对外暴露给外部连接
//int value = 10;

//可以
//常量采用内部链接，定义在头文件中，每个引用的源文件（.cpp文件）都会重新定义一遍，
//但是不会暴露给外部链接，于是整个链接过程总连接器就不会抱怨有多个一样定义的值在“对外列表”中了

//参见const_demo.cpp 中的bufz，必须通过extern 关键字才能对外暴露。
const int constValue = 10;


//3.常量数组里是常量吗？
//数组不会真的放在符号表中，所以必须分配内存
//而且编译的时候不需要知道数组中的值，所以很难把数组里面的值当作常量来使用
//参见const_demo.cpp

/*
 *4.const指针
 */
void constPointer();
const int* const cp=&constValue;

/*
 *作为函数的参数和返回值
 */
void constParam(const int param);
const int constReturnValue();

void constParamAndReturnValueTest();

/*
 *5.类中的常量
 */
class X{
    const int size;
    //a.编译期间常量，由该类产生的对象共享
    static const int initIndex = 0;
    //b.enum hack,之前老版的编译器不支持static const，用enum hack解决
    enum{enumIndex = 0};
    int a1[initIndex];
    int a2[enumIndex];
    
    int value = 0;
public:
    int getSize(){
        return size;
    }
    //c.常量必须在构造函数执行前执行，也就是这个“专用的位置”-构造函数初始化列表
    // X(){编译不通过
    //如果const int size; 没有初始化，那么这个显式的构造函数必须定义，否则编译不通过
    X():size(1){
        std::cout<<"X() size:"<<size<<std::endl;
    }
    //d.内建类型的“普通化”-把诸如int，float等内建n类型看成普通类型。
    //size(1)就是一种“普通化”的“构造函数”
    
    //e.常量对象的数据常量性控制的问题
    //普通函数
    void modifyMember(){
        std::cout<<"modifyMember"<< std::endl;
        value++;
    }
    
    //const后饰的函数
    void modifyMember() const{
        std::cout<<"modifyMember const"<< std::endl;
        //一个被const后饰的函数是不允许修改改对象的任何数据
        //因此value++编译无法通过
        //value++;
        //实现原理？
        //const后饰的函数中传递的this指针被转成const的了
        //即modifyMember(X this)变成modifyMember(const X this)
    }
    
    //f.按位与和按逻辑与
    //按位与：整个对象分毫不可被修改
    //按逻辑与：对象本身不可修改，但是它的成员可以被修改
    //默认行为是按位与
    //那么如何实现按逻辑与呢？有两种方案
    //方案一：强转
    void forceModify() const{
        ((X*)this)->value++;
        std::cout<<"forceModify value:"<<value<< std::endl;
    }
    //方案二：mutable关键字
    mutable int mutableValue=0;
    void mutableModify() const{
        mutableValue ++;
         std::cout<<"mutableModify value:"<<mutableValue<< std::endl;
    }
    //两个方案孰优孰劣？
    //自然是方案二，强转会带来问题，一个const的常量被莫名的修改了，会造成困惑，但是
    //mutable 修饰变量起到提醒调用者注意这个问题的作用，比偷摸的x强转修改要好
    
    static void test(){
        X x;
        x.modifyMember();
        std::cout<<x.getSize()<<std::endl;
        
        const X cx;
        //一个普通的函数不允许被一个const的对象调用，‘害怕‘破坏我的数据，我可是const的啊！
        //cx.modifyMember();
        //可以调用const后缀版本的函数
        cx.modifyMember();
        //由此可见，const后饰是函数原型的一部分，作为识别函数的一部分，一次虽然有两个‘一模一样的函数’，但是一个
        //是const的一个不是const，因此不会冲突，此处，编译器在处理的时候，会自动选择版本


        cx.forceModify();
        cx.mutableModify();
    }
};
inline void g1(X& x){}
inline void g2(const X& x){}
inline X generateX(){
    return X();
}

//6.volatile
//cost volatile:c-v限定词(c-v qualifier)

void constTest();
#endif /* const_demo_hpp */
