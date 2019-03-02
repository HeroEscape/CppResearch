//
//  main.cpp
//  CppResearch
//
//  Created by BruceYoung on 10/31/18.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include <iostream>

#include "homework/obj_count.h"

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
   // function_override_and_default_parm::multiConstructor();
    //useMacro();
    // insert code here...

	Z* z1 = new Z();
	Z* z2 = new Z();

	std::cout << Z::a<< std::endl;

	delete z1;
	delete z2;

	std::cout << Z::a << std::endl;

	system("pause");

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


