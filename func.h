#pragma once
#include <iostream>

using namespace std;

namespace funk {

}
namespace st {
	struct stack;
	void init(struct stack* stk);
	void push(struct stack* stk, float);
	float pop(struct stack* stk);
	float stkTop(struct stack* stk);
	int getcount(struct stack* stk);
	int isempty(struct stack* stk);
	void stkPrint(struct stack* stk);
}
