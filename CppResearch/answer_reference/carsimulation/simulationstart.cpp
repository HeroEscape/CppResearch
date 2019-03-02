//
//  simulationstart.cpp
//  CppResearch
//
//  Created by BruceYoung on 2018/12/30.
//  Copyright © 2018 BruceYoung. All rights reserved.
//

#include "simulationstart.hpp"
#include "car.hpp"
#include <unistd.h>
using namespace std;
void car_simulation::startSimulation(){
    int b=1;
  
    Car* car = new car_simulation::Car();
    long distance = 0;
    car->start();
    while(true){
        car->run();
        if(car->needAddGas()){
            cout<<"addGas"<<endl;
            car->addGas(45);
            
        }else{
            
        }
        distance+=100;
        if(distance>1200000){
            break;
        }
        
        cout<<"current distance:"<<distance<<endl;
        
        sleep(1);
        
        
    }
    
    delete car;
}
