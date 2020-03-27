#include "func.h"
const int NMAX = 1000;
struct st::stack {
	float elem[NMAX];
	int top;
};

void st::init(struct stack* stk) {
	stk->top = 0;
}
void st::push(struct stack* stk, float f) {
	if (stk->top < NMAX) {
		stk->elem[stk->top] = f;
		stk->top++;
	}
	else
		printf("���� �����, ���������� ���������: %d !\n", stk->top);
}
float st::pop(struct stack* stk) {
	float elem;
	if ((stk->top) > 0)
	{
		stk->top--;
		elem = stk->elem[stk->top];
		return elem;
	}
	else
	{
		printf("���� ����!\n");
		return 0;
	}
}
float st::stkTop(struct stack* stk) {
	if ((stk->top) > 0) {
		return stk->elem[stk->top - 1];
	}
	else {
		printf("���� ����!\n");
		return 0;
	}
}
int st::getcount(struct stack* stk) {
	return stk->top;
}
int st::isempty(struct stack* stk) {
	if (stk->top == 0)    return 1;
	else return 0;
}
void st::stkPrint(struct stack* stk) {
	int i;
	i = stk->top; // i - ���������� ��������� � �����
	if (isempty(stk) == 1) return; // ���� ����
	do {
		i--;
		printf("%f\n", stk->elem[i]);
	} while (i > 0);
}