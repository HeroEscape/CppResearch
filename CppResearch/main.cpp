//
//  main.cpp
//  CppResearch
//
//  Created by BruceYoung on 10/31/18.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include <iostream>
#include "misc/namespace_research.hpp"
extern "C"{
 #include "c_basic/c_func.h"
}
#include "c_basic/pointer.hpp"
#include "c_basic/grammar.hpp"
#include "c_basic/struct/struct_data.hpp"

#include "c_basic/struct/object_access.hpp"
#include "c_basic/function_override_and_default_param.hpp"


#include "homework/car.h"
#include "answer_reference/carsimulation/simulationstart.hpp"
#include "misc/inline_func.hpp"
#include "misc/const_demo.hpp"
#include "misc/name_control.hpp"

/*
 *1.File global namespace using
 *using namespace MySpace;
 */
/*
 *2Simplefy namespace with 'nickname'
 *namespace m = MySpace;
 */
int main(int argc, const char * argv[]) {
    std::cout<<"main start"<<std::endl;
    function_override_and_default_parm::multiConstructor();
    useMacro();
    // insert code here...
    //function_override_and_default_parm::defaultParm(1);
    //object_access::Car* car = new object_access::Car();
//    car-
//    useMacro();
//    inlineFunc();
//    (new InlineFuncDemo())->inlineFunc();
//    constTest();
//    nameControlMain();
    
    std::cout<<"main end"<<std::endl;
    return 0;
}


