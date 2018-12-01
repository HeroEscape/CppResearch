//
//  base.hpp
//  CppResearch
//
//  Created by BruceYoung on 11/15/18.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#ifndef base_hpp
#define base_hpp

#include <stdio.h>
//指针概述
void pointerSummary();
//指针的尺寸
void pointerSize();
//指针运算
void pointerOperation();

//指针和变量在内存中的关系
void pointerMemory();
void pointerWithNew();
//函数中的传值问题（在java等其他没有指针的语言中是一种困境）
void funcValueTrans();

//指针的指针以及多级指针
void pointerOfPointer();
//内存扫描（强大的来源，也是罪孽的根源）
void memoryScan();
//课后作业
void memoryFinder();
#endif /* base_hpp */
