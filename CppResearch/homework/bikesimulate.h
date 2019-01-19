#pragma once
#include<iostream>
using namespace std;
typedef struct Tili {
	struct TiliValue {
		int value = 50;
		int xiaoHao(int xiaohaoliang) {
			value = value - xiaohaoliang;
			cout << "presentvalue:" << value << endl;
			return(value);
		};
	};
	TiliValue* tiliValue = new TiliValue();
	void tilisimulate() {
		tiliValue->xiaoHao(1);
	}
	void clear() {
		delete tiliValue;
	}
}Tili;