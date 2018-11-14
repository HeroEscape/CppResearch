//
//  c_func.c
//  CppResearch
//
//  Created by BruceYoung on 11/3/18.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include "c_func.h"
void c_func(int a,int b){
    printf("a:%d",a);
    printf("b:%d",b);
}

void c_param_notsure(){
    printf("c_param_notsure");
}
int c_return_func(int a){
    printf("a:%d",a);
    return 0;
}
void c_for_in(){
    //int i=0;
    for(int i=0;i<100;i++){
        printf("%d\n",i);
    }
}
