//
//  container_iterator.cpp
//  CppResearch
//
//  Created by BruceYoung on 2019/1/25.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#include "container_iterator.hpp"

void containerIteratorTest(){
    Container container;
    
    for(int i=0;i<10;i++){
        container.add(new opreator_overwrite::Integer(i));
    }
    container.log();
    

    Container::Iterator it = container.it();
    while(it.hasNext()){
        it->log();
        ++it;
    }
}
