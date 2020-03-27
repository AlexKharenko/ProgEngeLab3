#include "func.h"
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
bool stack::isEmpty()
{
    return (top < 0);
};
class queue
{	
    
    int front;		
    int rear;		

public:
    int arr[MAX];
    queue() {
        front = 0;
        rear = 0;
    }
    void pop();
    bool push(int x);
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
bool queue::push(int item)
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

    char* x = argv[1];
    int count1 = 1;
    int count2 = 0;
    stack oper;
    for (int i = 0; i < strlen(argv[1]); i++)
        if ((char)argv[1][i] == '+' || (char)argv[1][i] == '-' || (char)argv[1][i] == '*' || (char)argv[1][i] == '/') {
            oper.push(argv[1][i]);
        }
    for (int i = 0; i < strlen(argv[1]); i++) {
        if (x[i] >= '0' && x[i] <= '9')
            continue;
        else count1++;
    }
    double* z = new double[count1];
    int k = 0;
    int n = strlen(x);
    for (int i = 0; i < n; i++) {
        if (x[i] >= '0' && x[i] <= '9')
            z[k] = z[k] * 10 + x[i] - '0';
        else k++;
    }
    queue numb;
    for (int i = 0; i < count1; i++) {
        numb.push(z[i]);
    }
    numb.output();



	return 0;
}