/*
initialize()
    top = 0

isEmpty()
    return top == 0

isFull()
    return top >= MAX - 1

push(x)
    if isFull()
        error: stack overflow
    top++
    S[top] = x

pop()
    if isEmpty()
        error: stack underflow
    top--
    return S[top+1]
*/

#include <bits/stdc++.h>
using namespace std;

int top, s[1000];

void push(int x){
    s[++top] = x;
}

int pop() {
    top--;
    return s[top+1];
}

int main() {
    int a, b;
    top = 0;

    string input;
    getline(cin, input);
    stringstream ss(input);
    while (getline(ss, input, ' '))
    {
        //cout << input << " " << endl;
        if (input == "+") {
            b = pop();
            a = pop();
            push(a + b);
            //cout << "a + b = " << a + b << endl;
        } else if (input == "-") {
            b = pop();
            a = pop();
            push(a - b);
            //cout << "a - b = " << a - b << endl;
        } else if (input == "*") {
            b = pop();
            a = pop();
            push(a * b);
            //cout << "a * b = " << a * b << endl;
        } else {
            push(stoi(input));
        }
    }
    cout << pop() << endl;
    return 0;
}
