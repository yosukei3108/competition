#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

int main() {
    stack<int> S;
    int a, b, x;
    string input;

    // getline(cin, input);
    // stringstream ss(input);
    while (cin >> input)
    {
        if (input[0] == '+') {
            b = S.top(); S.pop();
            a = S.top(); S.pop();
            S.push(a + b);
            //cout << "a + b = " << a + b << endl;
        } else if (input[0] == '-') {
            b = S.top(); S.pop();
            a = S.top(); S.pop();
            S.push(a - b);
            //cout << "a - b = " << a - b << endl;
        } else if (input[0] == '*') {
            b = S.top(); S.pop();
            a = S.top(); S.pop();
            S.push(a * b);
        } else {
            S.push(atoi(input.c_str()));
        }
    }
    cout << S.top() << endl;
    return 0;
}
