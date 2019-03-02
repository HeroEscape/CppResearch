//
//  inline_func.cpp
//  CppResearch
//
//  Created by BruceYoung on 2019/1/4.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#include "inline_func.hpp"
using namespace std;
void useMacro(){
    cout<<"use macro F(1):"<<F(1)<<endl;
}

//inline void inlineFunc(){
//    cout<<"inlineFunc"<<endl;
//}

void InlineFuncDemo::notInline(){
    cout<<"notInline"<<endl;
}

inline void InlineFuncDemo::forceInlineFunc(){
    cout<<"forceInlineFunc"<<endl;
}

