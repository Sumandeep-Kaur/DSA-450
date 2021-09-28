#include <iostream>
using namespace std;

class Stack
{
    int top;
    int n = 10;
    int st[n];
public: 
    Stack() { top = -1; }
    void push(int val);
    void pop();
    int peek();
    bool isEmpty();
    bool isFull();
};

void::Stack push(int val)
{
    if (top >= n - 1)
        cout << "Stack Overflow \n";
    else {
        top++;
        st[top] = val;
        cout << val << "pushed into stack \n";
    }
}
void::Stack pop()
{
    if (top < 0)
        cout << "Stack Underflow \n";
    else {
        cout << "The popped element is " << st[top] << endl;
        top--;
    }
}
int::Stack peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else
        return st[top];
}

bool::Stack isEmpty()
{
    return (top < 0);
}

bool::Stack isFull() 
{
    return (top == n - 1);
}

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    cout << s.isFull();
    return 0;
}