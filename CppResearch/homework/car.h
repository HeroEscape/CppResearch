#pragma once
#include<iostream>
typedef struct Bike {
	int name = 1;
	int price = 213541;
	struct Wheel {
		void run() {
			std::cout << "run" << std::endl;
		};
	};
	Wheel* frontwheel = new Wheel();
	Wheel* backwheel = new Wheel();
}Bike;
void carrun();