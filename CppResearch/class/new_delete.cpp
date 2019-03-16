//
//  new_delete.cpp
//  CppResearch
//
//  Created by BruceYoung on 2019/2/27.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#include "new_delete.hpp"
#include <cstdlib>
#include <new>
using namespace std;
//需要手动调用初始化函数和清理函数
void new_delete::cStyle(){
    Obj* obj = (Obj*)malloc(sizeof(Obj));
    obj->init();
    obj->destroy();
    free(obj);
}

//自动采用构造函数和析构函数
void new_delete::cppStyle(){
    Obj* obj = new Obj();
    delete obj;
}

/*我们发现在delete的时候析构函数并没有被调用,如果析构函数中
 *有重要的任务（比如清除其他对象），那么将会导致严重后果
*/
void new_delete::deleteVoidPointer(){
    void* obj = new Obj();
    delete obj;
}

void new_delete::deleteArray(){
    Obj* array = new Obj[1];
    //需要显示的调用[]
    delete [] array;
}

//内存耗尽后的处理函数
void out_of_memory(){
    cout<<"oom"<<endl;
    exit(1);
}
void new_delete::oom(){
    //设置内存耗尽后的处理函数
    set_new_handler(out_of_memory);
    while (1) {
        int* p = new int[1024*1024*1];
    }
}

