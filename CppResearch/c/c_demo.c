//
//  c_demo.c
//  CppResearch
//
//  Created by BruceYoung on 2018/12/26.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include "c_demo.h"
void callFuncWithoutDefine(){
    //这一段代码在c语言里面不会报错，只会警告，C语言编译器会自我“意淫”函数申明，即
    //时从来都没有申明f过
    //C中编译并不会报错，但是连接报错了
    //func_no_define();
}
