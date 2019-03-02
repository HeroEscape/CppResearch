//
//  const_demo.cpp
//  CppResearch
//
//  Created by BruceYoung on 2019/1/7.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#include "const_demo.hpp"
using namespace std;
extern const int bufz = 3;

int arr[3] = {1,2,3};
//关于数组中的常量
//如果用g++编译，这一段代码是无法通过的
int array2[BUFFER_SIZES[0]] = {4,5,6};

void constTest(){
//    const int* pB = &BUFFER_SIZE;
//
//    std::cout<<*pB<<std::endl;
//
//    std::cout<<arr[1]<<std::endl;
//
//    constPointer();
//    constParamAndReturnValueTest();
    
    X::test();
}
void constPointer(){
    //读法，cp是一个指针，指向一个const 的 int
    const int* cp;
    //首先cp这个指针本身不是const的，cp可以随意重新指向其他地方
    cp = &constValue;
    //然后cp这个指针指向的变量是const的，不能修改
    //*cp = 10;
    //-------------------------------------------------
    //读法，cp是一个指针，指向一个const 的 int，和前面一毛一样，const结合的是int而不是*
    int const* cp2;
    
    //-------------------------------------------------
    //这才表示一个指针本身是const的（所以必须初始化）
    int a = 10;
    int* const cp3 = &a;
    
    //一个值得注意的问题，字符数组在构建的时候实际上默认是常量数组，但是编译器接受以下形式
    char* c = "constPointer";
    std::cout<<c<<std::endl;
    //所以这一代码运行时必崩
    //*c='H';
    //这是一个C语言遗留的问题
}
//g++ c编译请打开
//int main(int argc, const char * argv[]) {
//    constTest();
//    return 0;
//}


int noConstReturnValue(){
    int a = 10;
    return a;
}
void noConstParam(int& param){
     cout<<"noConstParam=>param:"<<param<<endl;
}

void constParamAndReturnValueTest(){
    constParam(constReturnValue());
    constParam(noConstReturnValue());
    
    //函数产生临时变量，不管这个函数返回的是不是const变量，临时变量都是const的
    //所以不能当非const参数传递
    //noConstParam();
    //int a=noConstReturnValue();
    //noConstParam(noConstReturnValue());
    //noConstParam(constReturnValue());
    
}

void constParam(const int param){
    cout<<"constParam=>param:"<<param<<endl;
    
}
const int constReturnValue(){
    int a = 10;
    return a;
}
