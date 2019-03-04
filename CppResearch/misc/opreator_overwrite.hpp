//
//  opreator_overwrite.hpp
//  CppResearch
//
//  Created by BruceYoung on 2019/1/24.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#ifndef opreator_overwrite_hpp
#define opreator_overwrite_hpp

#include <stdio.h>
#include <iostream>
namespace opreator_overwrite{
    
    /*
     *1.一元运算符，二元运算符，三元运算符
     *一元运算符:+i,-i,i++,++i,i--,--i,...
     *二元运算符:i+j,i-j,i&&b,i^j,...
     *三元运算符:i>0?j:k
     *有几个数参与就是几元（元素）运算符
     */
    
    
    class Integer{
    private:
        int i;
        int* pi;
    public:
        int member;
        Integer():i(0){}
        Integer(int value):i(value){}
        
        //2.作为类的成员重载
        Integer operator+() const{//一元运算符
            std::cout<<"----------------------"<<std::endl;
            std::cout<<"Integer operator+ without arguments"<<std::endl;
            return Integer(i);
        }
        
        Integer operator+(const Integer& integer) const{//二元运算符
            std::cout<<"----------------------"<<std::endl;
            std::cout<<"Integer operator+"<<std::endl;
            return Integer(i+integer.i);
        }
       
        
        //3.作为全局重载
        friend Integer operator-(const Integer& integer);//一元运算符
        friend Integer operator-(const Integer& left, const Integer& right);//二元运算符
        
        //4.重载时如何区分先++和后++
        Integer operator++() const{//先++
            std::cout<<"----------------------"<<std::endl;
            std::cout<<"operator++()"<<std::endl;
            return Integer(i+1);
        }
        Integer operator++(int) const{//后++
            std::cout<<"----------------------"<<std::endl;
            std::cout<<"operator++(int)"<<std::endl;
            return Integer(i+1);
        }
        
        //移位操作
        Integer operator<<(int offset) const{
            std::cout<<"----------------------"<<std::endl;
            std::cout<<"operator<<"<<offset<<std::endl;
            return Integer(i<<offset);
        }
        
       
        
        /*
         *4.int指针运算符重载
         *返回一个指针，相当于在对象/引用+该操作符后返回一个指针
         *然后用这个指针进行操作
         */
        Integer* operator->(){
            std::cout<<"----------------------"<<std::endl;
            std::cout<<"operator->"<<std::endl;
            return this;
        }
        
        /*
         *5.练习：
         *a.创建一个Container的类，这个类的功能如下：
         *可以存放Integer 类对象，函数
         *add(Integer* integer)
         *b.在Container中创建一个内部类Iterator,功能如下：
         *用于迭代这个Container
         *Iterator& iterator = container.it();
         *iterator->log()
         *it++
         *可以询问这个迭代器迭代的边界，比如定义hasNext函数询问有没有迭代到结尾
         *
         *扩展练习，增加删除函数
         *remove(Integer* integer)
         */
        
        
        
        void log() const{
            std::cout<<"i:"<<i<<" member:"<<member<<std::endl;
        }
        
        int getI(){
            return i;
        }
        /*
         *6.->*运算符及其重载
         *指针指的是内存中的地址，类的成员变量作为一个变量，那么自然也有它的内存地址。
         *如何用指针取出类的成员变量的地址已经值？
         *两个问题
         *1.取址  &类名::成员变量名
         *2.定型  (成员变量类型 类名::*)变量名，注意括号是我自己加上去的，可以“看作一个新的类型”
         *那么对类的成员变量取址后赋给新的变量就是：
         *(成员变量类型 类名::*)变量名 = &类名::成员变量名
         */
        void memberPointer(){
            std::cout<<"=========memberPointer============="<<std::endl;
            int Integer::*pi = &Integer::i;
            this->*pi=4;
            log();
            std::cout<<"=================================="<<std::endl;
        }
        
        /*
         *->*重载
         */
        Integer operator->*(int Integer::*pMember){
           std::cout<<"->*"<<std::endl;
           return *this;
        }
        
    };
    void opreatorOverwriteTest();
    
    
    
}



#endif /* opreator_overwrite_hpp */
