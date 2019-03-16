//
//  template_generics.hpp
//  CppResearch
//
//  Created by BruceYoung on 2019/3/14.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#ifndef template_generics_hpp
#define template_generics_hpp

#include <stdio.h>
#include <iostream>
/*
 *1.我们创建一个Array类来扩展我们原生数组的能力
 */
class IntArray{
private:
    //初始化容量10
    int array[10];
public:
    void add(int i){
        array[i]=i;
        //如何实现自动扩容？
    }
    int get(int index){
        return array[index];
    }
    
};

/*
 *2.如果我们想要一个可以存放string的数组怎么办？
 *重新写一份？还是？
 *有三种解决方案：
 *1.C语言的解决方案：真的就是拷贝代码，然后手动修改，放弃
 *2.Smalltalk和Java（5.0以前的版本），采用基于对象的单根继承体系，也就是说任何一个对象
 *  都是继承自Object的，这是语言默认的行为，所以只要把int array[10];改成Object array[10];就可以存放任何类型的数据了
 *3.C++的做法，C++虽然从Smalltalk学习了很多做法，但是不包括基于对象的单根继承，因为任何对象默认继承Object在实际运行中需要
 *增加额外的开销，C++是注重效率的语言，所以不能接受，C++中如何做的呢？
 *有两种，第一种是多继承，显然会造成混乱
 *第二种就是今天的主题：模板
 */

template <class T>
class Array{
private:
    //初始化容量10
    T array[10];
public:
    void add(int index,T i){
        array[index]=i;
        //如何实现自动扩容？
    }
    T get(int index){
        return array[index];
    }
    
};

inline void test(){
    //普通Array
    IntArray intArray;
    for(int i=0;i<10;i++){
        intArray.add(i);
    }
    std::cout<<"IntArray:";
    for(int i=0;i<10;i++){
        std::cout<<intArray.get(i)<<",";
    }
    std::cout<<std::endl;
    
    //模板Array
    Array<int> array;
    for(int i=0;i<10;i++){
        array.add(i,i);
    }
    std::cout<<"Array<int>:";
    for(int i=0;i<10;i++){
        std::cout<<array.get(i)<<",";
    }
    std::cout<<std::endl;
    
    Array<std::string> arrayStr;
    for(int i=0;i<10;i++){
        std::string str = std::to_string(i);
        arrayStr.add(i,str);
    }
    
    std::cout<<"Array<std::string>:";
    for(int i=0;i<10;i++){
        std::cout<<arrayStr.get(i)<<",";
    }
    std::cout<<std::endl;
}
#endif /* template_generics_hpp */
