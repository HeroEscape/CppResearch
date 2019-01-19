//
//  name_control.cpp
//  CppResearch
//
//  Created by BruceYoung on 2019/1/17.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#include "name_control.hpp"
std::string name_control_namespace_test::slogon = "I love C++";
void name_control_namespace_test::multiFunc(){
    std::cout<<"name_control_namespace_test multiFunc"<<std::endl;
}
std::string name_control_namespace_test::slogon4C = "I love C";

void name_control_namespace_test2::multiFunc(){
     std::cout<<"name_control_namespace_test2 multiFunc"<<std::endl;
}


void usingNameSpace(){
    using namespace std;
    cout<<"usingNameSpace:"<<name_control_namespace_test::slogon<<endl;
    using namespace name_control_namespace_test;
    cout<<"usingNameSpace:"<<slogon4C<<endl;
    multiFunc();
    using namespace name_control_namespace_test2;
    //这一句无法编译通过，因为name_control_namespace_test和name_control_namespace_test2中都有multiFunc，会让编译器混淆
    //multiFunc();
    //但是我们可以用using加具体的函数来指定使用的命名空间
    using name_control_namespace_test2::multiFunc;
    multiFunc();
    
}


int name_control::Y::instanceCount = 0;

name_control::X name_control::Y::x("MyName");

void name_control::Y::staticFunc(){
    std::cout<<"name_control::Y::staticFunc instanceCount=>"<<instanceCount<<std::endl;
    
    //实际上，instanceCount在Y中应该是private才合适
    //为什么？
    //这个地方staticFunc可以作为instanceCount的访问器，instanceCount没有修改器，因此不会被外部随意修改
    //破坏了计数的准确性
}
