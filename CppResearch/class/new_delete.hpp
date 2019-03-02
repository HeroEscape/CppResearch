//
//  new_delete.hpp
//  CppResearch
//
//  Created by BruceYoung on 2019/2/27.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#ifndef new_delete_hpp
#define new_delete_hpp

#include <stdio.h>
#include <iostream>
#include <cstddef>
namespace new_delete{
    class Obj{
        int i;
    public:
        Obj(){
            std::cout<<"Constractor"<<std::endl;
        }
        ~Obj(){
            std::cout<<"Destractor"<<std::endl;
        }
        void init(){
            std::cout<<"init"<<std::endl;
        }
        void destroy(){
            std::cout<<"destroy"<<std::endl;
        }
    };
    
    class NewDeleteOverride{
    public:
        NewDeleteOverride(){
            std::cout<<"NewDeleteOverride()"<<std::endl;
        }
        ~NewDeleteOverride(){
            std::cout<<"~NewDeleteOverride()"<<std::endl;
        }
        void* operator new(size_t size){
            std::cout<<"new(size_t)"<<std::endl;
            void* m = malloc(size);
            return m;
        }
        void operator delete(void*){
            std::cout<<"delete(void*)"<<std::endl;
        }
        
    };
    /*
     *1.c的内存分配方式
     */
    void cStyle();
    void cppStyle();
    
    /*
     *2.delete void*
     */
    void deleteVoidPointer();
    /*
     *3.数组的删除
     */
    void deleteArray();
    /*
     *4.当内存耗尽的时候会发生什么
     */
    void oom();
}
#endif /* new_delete_hpp */
