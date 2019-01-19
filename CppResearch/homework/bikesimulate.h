#pragma once
#include<iostream>
using namespace std;
typedef struct Tili {
	struct tilivalue {
		int value = 50;
		int xiaohaoliang = 0.1
		void xiaohao(xiaohaoliang){
			value = value - xiaohaoliang
			cout << "presentvalue:" << value << endl;
			return(value);
		};
	};
	tilivalue* tilivalue1 = new tilivalue();
	void tilisimulate() {
		tilivalue1->xiaohao();
	}
	void clear() {
		delete tilivalue1;
	}
}Tili;