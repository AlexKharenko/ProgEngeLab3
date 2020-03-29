﻿#include "func.h"
#include <string>
#include <cstdlib> 

using namespace std;

#include<iostream>
using namespace std;

#define MAX 1000 

class stack
{
    int top;
public:
    char myStack[MAX]; 

    stack() { top = -1; }
    bool push(char x);
    char pop();
    char back();
    int size();
    bool isEmpty();
    void output();
};
bool stack::push(char item)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow!!!";
        return false;
    }
    else {
        myStack[++top] = item;
        cout << item << endl;
        return true;
    }
}
char stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow!!";
        return 0;
    }
    else {
        char item = myStack[top--];
        return item;
    }
}
char stack::back()
{
    return myStack[top];
}
int stack::size()
{
    return top+1;
}
void stack::output() {
    for (int i = 0; i < size(); i++)
    {
        cout << myStack[i] << " ";
    }
    cout << endl;
}
bool stack::isEmpty()
{
    return (top < 0);
};
class queue
{	
    
    int front;		
    int rear;		

public:
    char arr[MAX];
    queue() {
        front = 0;
        rear = 0;
    }
    void pop();
    bool push(char x);
    int type_front();
    int size();
    bool isEmpty();
    bool isFull();
    void output();
};
void queue::pop()
{
    if (isEmpty())
    {
        cout << "UnderFlow\n";
        exit(EXIT_FAILURE);
    }
    cout << "Removing " << arr[front] << '\n';
    front++;
}
bool queue::push(char item)
{
    if (isFull())
    {
        cout << "OverFlow\n";
        exit(EXIT_FAILURE);
    }
    cout << "Inserting " << item << '\n';
    arr[rear++] = item;
    return true;
}
int queue::type_front()
{
    if (isEmpty())
    {
        cout << "UnderFlow\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}
int queue::size()
{
    return rear+1;
}
bool queue::isEmpty()
{
    return (size() == 0);
}
bool queue::isFull()
{
    return (size() == MAX);
}
void queue::output() {
    if (isEmpty())
    {
        cout << "UnderFlow\n";
        exit(EXIT_FAILURE);
    }
    for (int i = front; i < rear; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    queue out;
    stack oper;
	int counter = 0;
    for (int j = 1; j < argc; ++j)
    {
        int i = 0;
        while (i < strlen(argv[j])) {
            char s = oper.back();
            if ((char)argv[j][i] == ' ') {
                continue;
            }
            if ((char)argv[j][i] >= '0' && (char)argv[j][i] <= '9') {
                out.push(argv[j][i]);
                i++;
                continue;
            }
            if ((char)argv[j][i] == '+' || (char)argv[j][i] == '-') {
                oper.push(argv[j][i]);
                i++;
				counter++;
                continue;
            }
            if ((char)argv[j][i] == '*' || (char)argv[j][i] == '/' && s == '+' || s == '-') {
                oper.push(argv[j][i]);
                i++;
				counter++;
                continue;
            }
            if ((char)argv[j][i] == '*' || (char)argv[j][i] == '/' && s == '*' || s == '/') {
                int l = oper.pop();
                out.push(l);
                oper.push(argv[j][i]);
                i++;
				counter++;
                continue;
            }
            else {
                continue;
            }
        }
        i = 0;
    }
    for (int i = 0; i =oper.size() ; i++) {
            int l = oper.pop();
            out.push(l);
    }
	cout << "counter" << counter << endl;
    out.output();
	int result = 0;
	int change = 0;
	int change2 = 0;
	for (int l = counter; counter >= 1;counter--) {
		for (int i = 0; i < out.size() ; i++) {
			if (out.arr[i] == '*') {
				change = out.arr[i - 1] - '0';
				change2 = out.arr[i - 2] - '0';
				result = change * change2;
				for (int j = i; j < out.size() - 1; j++) {
					out.arr[j] = out.arr[j + 1];
					out.arr[j + 1] = '0';
				}
				for (int k = i; k < out.size()-1 ; k++) {
					out.arr[k - 1] = out.arr[k - 2];
					out.arr[k - 2] = 0;
					out.arr[k - 1] = result;
				}
				out.arr[i - 2] = 0;
				i--;
			}
			if (out.arr[i] == '-') {
				change = out.arr[i - 2] - '0';
				change2 = out.arr[i - 1] - '0';
				result = change - change2;
				for (int j = i; j < out.size() - 1; j++) {
					out.arr[j] = out.arr[j + 1];
					out.arr[j + 1] = '0';
				}
				for (int k = i; k < out.size()-1 ; k++) {
					out.arr[k - 1] = out.arr[k - 2];
					out.arr[k - 2] = 0;
					out.arr[k - 1] = result;
				}
				out.arr[i - 2] = '0';
				i--;
			}
			if (out.arr[i] == '+') {
				change = out.arr[i - 1] - '0';
				change2 = out.arr[i - 2] - '0';
				result = change + change2;
				for (int j = i; j < out.size() - 1; j++) {
					out.arr[j] = out.arr[j + 1];
					out.arr[j + 1] = '0';
				}
				for (int k = i; k < out.size()-1 ; k++) {
					out.arr[k - 2] = out.arr[k - 1];
					out.arr[k - 1] = 0;
					out.arr[k - 2] = result;
				}
				out.arr[i - 2] = '0';
				i--;
				
				cout << "Result:" << result << endl;
			}
		}
		cout << "counter - " << counter << endl;
	}
	cout<<"Result:"<<result<<endl;
	return 0;
}