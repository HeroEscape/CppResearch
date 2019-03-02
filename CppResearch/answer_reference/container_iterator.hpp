//
//  container_iterator.hpp
//  CppResearch
//
//  Created by BruceYoung on 2019/1/25.
//  Copyright © 2019 BruceYoung. All rights reserved.
//

/*
 *运算符重载练习-容器和迭代器：
 *a.创建一个Container的类，这个类的功能如下：
 *可以存放Integer 类对象，函数
 *add(Integer* integer)
 *b.在Container中创建一个内部类Iterator,功能如下：
 *用于迭代这个Container
 *Iterator& iterator = container.it();
 *iterator->log()
 *it++
 *
 *扩展练习，增加删除函数
 *remove(Integer* integer)
 */

#ifndef container_iterator_hpp
#define container_iterator_hpp

#include <stdio.h>
#include "Container.hpp"
void containerIteratorTest();

#endif /* container_iterator_hpp */
