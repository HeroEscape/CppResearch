//
//  extends.hpp
//  CppResearch
//
//  Created by BruceYoung on 2019/2/28.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#ifndef extends_hpp
#define extends_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
namespace extends {
    
class Car{
    private:
        string brand;
    public:
        Car(){
            cout<<"Car()"<<endl;
        }
        string getBrand(){
            return brand;
        }
    
        void run(){
            cout<<"Car run"<<endl;
        }
    
        void showLog(){
            cout<<"Car log"<<endl;
        }
    };
    /*
     *1.组合
     */
    class Ferrari{
    private:
        //把其他类对象组装进去
        Car* car;
        
    public:
        Ferrari(){
            car = new Car();
        }
        ~Ferrari(){
            delete car;
        }
        //利用成员的函数
        void run(){
            car->run();
        }
        void showLog(){
            car->showLog();
        }
        
    };
    
    /*
     *2.继承
     *直接继承其他类，使之产生的“子类”拥有“父类”的能力
     */
    class Porsche:public Car{
    private:
        string model;
    public:
        Porsche(){
            cout<<"Porsche()"<<endl;
        }
        void showLog(){
            cout<<"Porsche log"<<endl;
        }
    };
    
    /*
     *4.子类父类的构造函数和析构函数
     */
    class Animal{
        string name;
    public:
        Animal(string name){
            this->name = name;
            cout<<"Animal()"<<endl;
        }
        
        ~Animal(){
            cout<<"~Animal()"<<endl;
        }
        void bark(){
            cout<<"I am "<<firstName<<"-"<<name<<endl;
        }
        //7.protected 关键字,对外不可访问，但是子类可以访问
    protected:
        string firstName;
    };
    class Dog:public Animal{
    public:

        Porsche* porsche;
        Dog():Animal("wangwang"){
            cout<<"Dog()"<<endl;
            firstName = "dog";
        }
        ~Dog(){
            cout<<"~Dog()"<<endl;
        }
    };
    
    /*
     *6.私有继承
     */
    class Cat:Animal{//默认是私有继承
    public:
        Cat():Animal("miaomiao"){
            cout<<"Cat()"<<endl;
            firstName = "cat";
        }
        ~Cat(){
            cout<<"~Cat()"<<endl;
        }
        using Animal::bark;//可以这样单点公开
    };
    
    /*
     *8.扩展:多重继承和渐进开发
     */

    void test();
    
}




#endif /* extends_hpp */
