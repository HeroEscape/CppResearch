//
//  copy_constructor.cpp
//  CppResearch
//
//  Created by BruceYoung on 2019/1/23.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#include "copy_constructor.hpp"
void copy_constructor::func(X x){
    std::cout<<"func with value X x"<<std::endl;
    x.log();
    
}

//返回值比较特殊
//RVO（Return Value Optimistic）编译优化技术会在按值返回的时候，不调用拷贝构造函数
//这里我们手动“迷惑”编译器不执行RVO优化
copy_constructor::X copy_constructor::funcWithValue4Return(){
    X x;
    if(true){//让编译器“搞不清”返回哪一个,就不会RVO了
       return x;
    }else{
        return X();
    }
}

void copy_constructor::func(X* x){
    std::cout<<"func with pointer X* x"<<std::endl;
    x->log();
}
copy_constructor::X* copy_constructor::funcWithPointer4Return(){
    X x;
    return &x;
}

void copy_constructor::funcWithRef(X& x){
    std::cout<<"func with ref X& x"<<std::endl;
    x.log();
}
copy_constructor::X& copy_constructor::functionWithRef4Return(){
    X x;
    return x;
}
