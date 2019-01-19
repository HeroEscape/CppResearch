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
	void bikerun() {
		frontwheel->run();
		backwheel->run();
	}
	void bikedelete() {
		delete frontwheel;
		delete backwheel;
	}
}Bike;
void bikerun();