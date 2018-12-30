//
//  Wheel.hpp
//  CppResearch
//
//  Created by BruceYoung on 2018/12/30.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#ifndef Wheel_hpp
#define Wheel_hpp

#include <stdio.h>
#include <iostream>
namespace car_simulation{
    
    class Wheel{
    public:
        void run(){
            std::cout<<"wheel run"<<std::endl;
        }
        void stop(){
            std::cout<<"wheel stop"<<std::endl;
        }
    };
}
#endif /* Wheel_hpp */
