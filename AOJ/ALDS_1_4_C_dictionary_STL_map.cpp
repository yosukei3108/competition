#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    char str[10], com[13];
    map<string, bool> T;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> com >> str;
        if (com[0] == 'i') T[string(str)] = true;
        else {
            if (T[string(str)]) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}
