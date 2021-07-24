#include <iostream>
using namespace std;

#define MAX 100005
#define NaN -1

struct Node {
    int parent, left, right;
};

Node T[MAX];
int n, D[MAX], H[MAX];

void setDepth(int u, int d) {
    // cout << "u = " << u << ", d = " << d << endl;
    if(u == NaN) return;
    D[u] = d;
    // cout << "D[" << u << "] = " << D[u] << endl;
    setDepth(T[u].left, d+1);
    // cout << "set depth of T[" << u << "].left as " << d+1 << endl;
    setDepth(T[u].right, d+1);
    // cout << "set depth of T[" << u << "].right as " << d+1 << endl;

}

int setHeight(int u) {
    int h1 = 0; int h2 = 0;
    if(T[u].left != NaN)
        h1 = setHeight(T[u].left) + 1;
    if(T[u].right != NaN)
        h2 = setHeight(T[u].right) + 1;

    return H[u] = ( h1 > h2 ? h1: h2);
}

int getSibling(int u) {
    if (T[u].parent == NaN)
        return NaN;
    if (T[T[u].parent].left != u && T[T[u].parent].left != NaN)
        return T[T[u].parent].left;
    if (T[T[u].parent].right != u && T[T[u].parent].right != NaN)
        return T[T[u].parent].right;

    return NaN;
}

void print(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "sibling = " << getSibling(u) << ", ";

    int deg = 0;
    if(T[u].left != NaN) deg++;
    if(T[u].right != NaN) deg++;
    cout << "degree = " << deg << ", ";
    cout << "depth = " << D[u] << ", ";
    cout << "height = " << H[u] << ", ";

    if(T[u].parent == NaN) cout << "root" << endl;
    else if(T[u].left == NaN && T[u].right == NaN) cout << "leaf" << endl;
    else cout << "internal node" << endl;
}

int main() {
    int v = 0;
    int l = 0;
    int r = 0;
    int root = 0;

    cin >> n;

    for(int i=0; i<n; i++) T[i].parent = NaN;

   //  cout << "initialize T" << endl;
    // cout << "T[0].parent = " << T[0].parent << endl;

    for(int i=0; i<n; i++) {
        cin >> v >> l >> r;
        T[v].left = l;
        T[v].right = r;
        if(l != NaN) T[l].parent = v;
        if(r != NaN) T[r].parent = v;
    }

    // cout << "read input" << endl;

    for(int i=0; i<n; i++) if(T[i].parent == NaN) root = i;

    // cout << "write root with i" << endl;

    setDepth(root, 0);
    // cout << "setDepth processed" << endl;
    setHeight(root);

    for(int i=0; i<n; i++) print(i);

    return 0;

}
