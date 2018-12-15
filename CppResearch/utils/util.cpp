//
//  util.cpp
//  CppResearch
//
//  Created by BruceYoung on 2018/12/6.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include "util.hpp"
#include <iostream>
using namespace std;
void printBinary(int value){
    for(int i=32;i>=0;i--){
        if(value & (1<<i)){
            cout<<"1";
        }else{
            cout<<"0";
        }
        
    }
    cout<<endl;
}
