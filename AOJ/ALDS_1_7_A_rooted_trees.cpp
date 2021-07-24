#include <iostream>
using namespace std;

#define MAX 100005
#define NaN -100

struct Node { int p, l, r; };

Node T[MAX];
int n, D[MAX];

void print(int u) {
    cout << "node " << u << ": ";
    cout << "parent" << T[u].p << ", ";
    cout << "depth" << D[u] << ", ";

    if(T[u].p == NaN) cout << "root, ";
    else if(T[u].l == NaN) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";

    int i, c;

    for(i=0, c=T[u].l; c!=NaN; i++, c=T[c].r) {
        if(i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

int depth_rec(int u, int p) {
    cout << "depth_rec()" << endl;
    cout << "input: u = " << u << ", p = " << p << endl;

    D[u] = p;
    
    if(T[u].r != NaN) cout << "T[u].r should not be -100, but T[u].r is " << T[u].r << endl;
    
    
    if(T[u].r != NaN) {
        cout << "right sibling has found" << endl;
        depth_rec(T[u].r, p);
    } else {
        cout << "right sibling has NOT found" << endl;
    }

    if(T[u].l != NaN) {
        cout << "T[u].l should not be -100, but T[u].l is " << T[u].l << endl;
        cout << "typeid(T[u].l).name() = " << typeid(T[u].l).name() << endl;
        cout << "typeid(NaN).name() = " << typeid(NaN).name() << endl;
    }

    if(T[u].l != NaN) {
        cout << "left child has found" << endl;
        depth_rec(T[u].l, p+1);
    } else {
        cout << "left child has NOT found" << endl;
    }
}

int main() {
    int i, j, d, v, c, l, r;
    cin >> n;
    
    for(i=0; i<n; i++) {
        T[i].p = NaN;
        T[i].l = NaN;
        T[i].r = NaN;
    }

    for(i=0; i<n; i++) {
        cin >> v >> d;
        for(j=0; j<d; j++) {
            cin >> c;
            
            if(j == 0) {
                T[v].l = c;
                cout << "T[v].l = " << T[v].l << endl;
            } else {
                T[l].r = c;
                cout << "T[l].r = " << T[l].r << endl;
            }
            l = c;
            T[c].p = v;
        }
    }
    for(i=0; i<n; i++) {
        if(T[i].p == NaN) {
            r = i;
            cout << "r has set as " << i << endl; 
        }
    }

    depth_rec(r, 0);

    for(i=0; i<n; i++) print(i);

    return 0;

}