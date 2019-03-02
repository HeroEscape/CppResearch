//
//  extends.cpp
//  CppResearch
//
//  Created by BruceYoung on 2019/2/28.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

#include "extends.hpp"
void extends::test(){
    Porsche porscheCar;
    //Porsche 自动获取“父类”的run函数
    porscheCar.run();
    cout<<"============"<<endl;
    
    //Ferrari 通过组合的方式显式拥有run函数
    Ferrari ferrariCar;
    ferrariCar.run();
    cout<<"============"<<endl;
    
    
    /*3.测试Car和Porsche的尺寸
     *发现Porsche是Car的两倍
     *说明继承的属性被复制到子内中了
     */
    cout<<"Car size"<<sizeof(Car)<<endl;
    cout<<"Porsche size"<<sizeof(Porsche)<<endl;
    cout<<"============"<<endl;

    /*
     *4.继承体系下的构造函数
     *父类构造->子类构造
     *子类析构->父类析构
     *总结：类似“栈”的结构->先进后出，后进先出。
     */
    
    Dog* dog = new Dog();
    dog->bark();
    delete dog;
    cout<<"============"<<endl;
    
    
    //5.Porsche 覆盖了 Car的 showLog()函数
    extends::Car* car = new extends::Porsche();
    car->showLog();
    extends::Porsche* porsche = new extends::Porsche();
    porsche->showLog();
    //上述的两个showLog有什么区别？
    //这是一个早绑定和晚绑定的问题
    //多态和虚函数的作用
    
    //6.私有继承
    cout<<"============"<<endl;
    Cat cat;
    cat.bark();
    cout<<"============"<<endl;
    
    
    delete car;
}
