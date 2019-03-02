//
//  Container.hpp
//  CppResearch
//
//  Created by BruceYoung on 2019/1/25.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#ifndef Container_hpp
#define Container_hpp

#include <stdio.h>
#include "../misc/opreator_overwrite.hpp"
class Container{
public:
    class Iterator{
        int currentIndex = 0;
        Container& container;
    public:
        Iterator(Container& container):container(container){}
        opreator_overwrite::Integer* operator->(){
            opreator_overwrite::Integer* pInteger = container.arrays[currentIndex];
            return pInteger;
        }
        void operator++(){
            currentIndex++;
        }
        
        bool hasNext(){
            if(currentIndex<container.size){
                return true;
            }
            return false;
            
        }
    };
private:
    opreator_overwrite::Integer** arrays;
    int size = 0;
    Iterator* iterator;
public:
    Container(){
        arrays = new opreator_overwrite::Integer*[2]();
        iterator = new Iterator(*this);
    }
    ~Container(){
        delete arrays;
        delete iterator;
    }
    void add(opreator_overwrite::Integer* integer){
      
        //copy data to tempArray
        opreator_overwrite::Integer** tempArrays = new opreator_overwrite::Integer*[size+1]();
        for(int i=0;i<size;i++){
            tempArrays[i]=arrays[i];
        }
        tempArrays[size]=integer;
        delete [] arrays;
        arrays = tempArrays;
        
        size++;
    }
    void log(){
        std::cout<<"[";
        for(int i=0;i<size;i++){
            std::cout<<(*arrays[i]).getI()<<",";
        }
        std::cout<<"]"<<std::endl;
    }
    
    
    Iterator& it(){
        return *iterator;
    }
    
    
};
#endif /* Container_hpp */
