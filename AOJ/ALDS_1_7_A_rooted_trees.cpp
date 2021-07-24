#include <iostream>
using namespace std;

#define MAX 100005
#define NaN -1

struct Node { int p, l, r; };

Node T[MAX];
int n, D[MAX];

void print(int u) {
    int i, c;
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "depth = " << D[u] << ", ";

    if(T[u].p == NaN) cout << "root, ";
    else if(T[u].l == NaN) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";

    for(i=0, c=T[u].l; c!=NaN; i++, c=T[c].r) {
        if(i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

void depth_rec(int u, int p) {
    // cout << "into depth_rec()" << endl;

    D[u] = p;

    // cout << "D[u] = " << D[u] << endl;

    // cout << "T[u].r = " << T[u].r << endl;
    if(T[u].r != NaN) depth_rec(T[u].r, p);

    // cout << "T[u].l = " << T[u].l << endl;
    if(T[u].l != NaN) depth_rec(T[u].l, p+1);
}

int main() {

    // cout << "start main()" << endl;

    int i, j, d, v, c, l, r;
    cin >> n;

    for(i=0; i<n; i++) {
        T[i].p = NaN;
        T[i].l = NaN;
        T[i].r = NaN;
    }

    // cout << "initialize T" << endl;
    // cout << "T[0].p = " << T[0].p << endl;

    for(i=0; i<n; i++) {
        cin >> v >> d;
        for(j=0; j<d; j++) {
            cin >> c;
            if(j == 0) T[v].l = c;
            else T[l].r = c;
            l = c;
            T[c].p = v;
        }
    }

    // cout << "read input" << endl;

    for(i=0; i<n; i++) {
        if(T[i].p == NaN) r = i;
    }

    // cout << "write r with i" << endl;

    depth_rec(r, 0);

    for(i=0; i<n; i++) print(i);

    return 0;

}
