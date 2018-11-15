//
//  do_and_while.cpp
//  CppResearch
//
//  Created by BruceYoung on 11/3/18.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include "cpp_func.hpp"

#include <iostream>
using namespace std;
void while_func(){
    int secret = 15;
    int guess=0;
    cout<<guess<<endl;
    while(guess != secret){
        cout<<"guess what"<<endl;
        cin>>guess;
        cout<<"guess what end"<<endl;
    }
}
void do_while_func(){
    int secret = 15;
    int guess;
    do{
        cout<<"guess what"<<endl;
        cin>>guess;
    }while (secret != guess);
  
}


