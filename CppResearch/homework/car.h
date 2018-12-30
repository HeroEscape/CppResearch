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
	void bikerun() {
		Wheel* frontwheel = new Wheel();
		Wheel* backwheel = new Wheel();

		frontwheel->run();
		backwheel->run();
		delete frontwheel;
		delete backwheel;
	}
}Bike;
void carrun();