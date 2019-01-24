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
    public:
        Integer(int value):i(value){}
        
        //2.作为类的成员重载
        Integer operator+() const{//一元运算符
            std::cout<<"Integer operator+ without arguments"<<std::endl;
            return Integer(i);
        }
        
        Integer operator+(const Integer& integer) const{//二元运算符
            std::cout<<"Integer operator+"<<std::endl;
            return Integer(i+integer.i);
        }
       
        //3.作为全局重载
        friend Integer operator-(const Integer& integer);//一元运算符
        friend Integer operator-(const Integer& left, const Integer& right);//二元运算符
        
        //4.重载时如何区分先++和后++
        Integer operator++() const{//先++
            std::cout<<"operator++()"<<std::endl;
            return Integer(i+1);
        }
        Integer operator++(int) const{//后++
            std::cout<<"operator++(int)"<<std::endl;
            return Integer(i+1);
        }
        
        //移位操作
        Integer operator<<(int offset) const{
            std::cout<<"operator<<"<<offset<<std::endl;
            return Integer(i<<offset);
        }
        
        
        
        void log() const{
            std::cout<<"i:"<<i<<std::endl;
        }
        
    };
    void opreatorOverwriteTest();
    
    
}



#endif /* opreator_overwrite_hpp */
