#include<iostream>
#include "bikesimulate.h"
#include "bike.h"
using namespace std;
void bikesimulate() {
	int distanceleft = 50;
	int speed = 1;
	Bike bike1;
	Tili tili1;
	while (distanceleft > 0)
	{
		int time = 0;
		bike1.bikerun();
		tili1.tilisimulate()£»
		distanceleft = distanceleft - speed;
		cout << "distanceleft:" << distanceleft << endl;
		if (value <= 0) {
			cout << "need rest  resting" << endl;
			time += 3;
			value = 50;
		}
		time += 1;
	}
	bike1.bikedelete();
	tili1.clear();
	cout << "totaltime:" << time << endl;
}