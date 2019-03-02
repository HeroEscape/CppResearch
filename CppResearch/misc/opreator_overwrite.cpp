//
//  opreator_overwrite.cpp
//  CppResearch
//
//  Created by BruceYoung on 2019/1/24.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#include "opreator_overwrite.hpp"
using namespace opreator_overwrite;
using namespace std;
void opreator_overwrite::opreatorOverwriteTest(){
    opreator_overwrite::Integer integer(1);
    integer.log();
    (integer+integer).log();
    (+integer).log();
    (-integer).log();
    (integer-integer).log();
    
    (integer++).log();
    (++integer).log();
   
    (integer<<2).log();
    (integer<<4).log();
}

Integer opreator_overwrite::operator-(const Integer& integer){
    std::cout<<"Integer operator-"<<std::endl;
    return Integer(-integer.i);
}
Integer opreator_overwrite::operator-(const Integer& left, const Integer& right){
    std::cout<<"Integer operator-"<<std::endl;
    return Integer(left.i-right.i);
}

