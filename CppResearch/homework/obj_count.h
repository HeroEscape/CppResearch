#pragma once
class Z {
public:
	static int a;
	Z() {
		a++;
	}
	~Z() {
		a--;
	}
};