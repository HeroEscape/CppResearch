//
//  grammar.cpp
//  CppResearch
//
//  Created by BruceYoung on 11/29/18.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include "grammar.hpp"
#include <iostream>
using namespace std;
/*
 *                  value=2
 *                     |
 *  |--------|         |
 *  |___0____|         |jump
 *  |___1____|         |
 *  |___2____|<--------|
 *  |___3____| |\__________break_____->
 *  |___4____| |
 *             |继续执行
 *             |
 *             v
 *如果switch没有break的话，所有的分支都要走
 */
void switchBreak(int value){
    switch (value) {
        case 0:{
            cout<<"value is 0"<<endl;
        }
        case 1:{
           cout<<"value is 1"<<endl;
        }
        case 2:{
            cout<<"value is 2"<<endl;
        }
        case 3:{
            cout<<"value is 3"<<endl;
        }
        default:{
            cout<<"value is thers"<<endl;

        }
            
    }
}

/*
 *goto很厉害，但是也很危险，容易造成程序的混乱，作为异种骨后备的trick，不能当作日常用法
 */
void badGoto(){
    for(int i=0;i<100;i++){
        cout<<"i:"<<i<<endl;
        for(int j=0;j<100;j++){
            cout<<"j:"<<j<<endl;
            if(j>10){
                //break;
                //goto bottom;
            }
        }
    }
bottom:
    cout<<"end"<<endl;
}

void sign(){
    unsigned char i = -1;
    cout<<"i:"<<int(i)<<endl;
    char j = -1;
    cout<<"j:"<<int(j)<<endl;
}

void variableChange(){
    int a = 0;
    static int sa = 0;
    cout<<"a:"<<a<<endl;
    cout<<"sa:"<<sa<<endl;
    a++;
    sa++;
}

void staticVariable(){
    for(int i=0;i<10;i++){
        variableChange();
    }
}


extern int thirdpart_value;
void useExtern(){
    cout<<"thirdpart_value:"<<thirdpart_value<<endl;
    // statuc value can not be linked from outter
    //cout<<thirdpart_static_value<<endl;
}


#define PI 3.14
void useConst(){
    cout<<"PI"<<PI<<endl;
    
}
