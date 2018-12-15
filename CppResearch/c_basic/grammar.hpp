//
//  grammar.hpp
//  CppResearch
//
//  Created by BruceYoung on 11/29/18.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#ifndef grammar_hpp
#define grammar_hpp

#include <stdio.h>
//1.switch break
void switchBreak(int value);
//2.goto
void badGoto();
//3.有符号和无符号数据
void sign();

//4.静态变量
void staticVariable();

//5.外部变量
void useExtern();

//*6.常量
void useConst();

//7.二进制操作
void binaryOpreation();

//**8.函数指针，指针函数
void functionAddress(int funcIndex);

//课后练习，强化函数指针，指针函数的概念
void homework();
#endif /* grammar_hpp */
