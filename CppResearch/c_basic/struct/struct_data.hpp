//
//  struct_data.hpp
//  CppResearch
//
//  Created by BruceYoung on 2018/12/15.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#ifndef struct_data_hpp
#define struct_data_hpp

#include <stdio.h>
#include <string>
typedef struct Car{
    //成员变量
    std::string name;
    float price;
    int type;
    //成员函数
    void tellInfo();
    //4.构造函数
    Car();
    
} Car;
//1.预览
void previewStruct();
Car* createCar(std::string name,float price,int type);
//2.动态内存分配
void dynamicMem();

//3.函数成员
void functionMember();

//5.对象的内存分布
void objectMem();
#endif /* struct_data_hpp */
