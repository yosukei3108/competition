#include <bits/stdc++.h>
using namespace std;

#define M 1048583
#define L 13

string H[M];

int getChar (char ch) {
    if (ch=='A') return 1;
    else if (ch=='C') return 2;
    else if (ch=='G') return 3;
    else if (ch=='T') return 4;
    else return 0;
}

long long getKey(string str) {
    long long sum = 0;
    long long p = 1;
    long long i;
    for (i=0; i<str.length(); i++) {
        sum += p * (getChar(str[i]));
        p *= 5;
    }
    return sum;
}

int h1 (int key) { return key % M; }
int h2 (int key) { return 1 + (key % (M - 1)); }

int myfind (string str) {
    long long key, i, h;
    key = getKey(str);
    for (i=0; ;i++) {
        h = (h1(key) + i * h2(key)) % M;
        if (H[h] == str) return 1;
        else if(H[h].length() == 0) return 0;
    }
    return 0;
}

int myinsert (string str) {
    long long key, i, h;
    key = getKey(str);
    for (i=0; ;i++) {
        h = (h1(key) + i * h2(key)) % M;
        if (H[h] == str) return 1;
        else if(H[h].length() == 0) {
            H[h] = str;
            return 0;
        }
    }
    return 0;
}

int main () {
    int i, n, h;
    string com, str;

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        cin >> com >> str;
        if (com[0] == 'i') myinsert(str);
        else {
            if (myfind(str)) printf("yes\n");
            else printf("no\n");
            }
    }
    return 0;
}