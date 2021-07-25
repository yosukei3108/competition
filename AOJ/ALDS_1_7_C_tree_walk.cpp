#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
#define NIL -1

struct Node {
    int parent, left, right;
};
struct Node T[MAX];
int n;

void preParse(int u) {
    // cout << "u = " << u << endl;
    if(u == NIL) return;

    cout << " " << u;

    preParse(T[u].left);
    preParse(T[u].right);
}

void inParse(int u) {
    // cout << "u = " << u << endl;
    if(u == NIL) return;

    inParse(T[u].left);

    cout << " " << u;

    inParse(T[u].right);
}

void postParse(int u) {
    // cout << "u = " << u << endl;
    if(u == NIL) return;

    postParse(T[u].left);
    postParse(T[u].right);

    cout << " " << u;
}

int main() {
    int v = 0;
    int l = 0;
    int r = 0;
    int root = 0;

    cin >> n;

    for(int i=0; i<n; i++) T[i].parent = NIL;

   //  cout << "initialize T" << endl;
    // cout << "T[0].parent = " << T[0].parent << endl;

    for(int i=0; i<n; i++) {
        cin >> v >> l >> r;
        T[v].left = l;
        T[v].right = r;
        if(l != NIL) T[l].parent = v;
        if(r != NIL) T[r].parent = v;
    }

    // cout << "read input" << endl;

    for(int i=0; i<n; i++) if(T[i].parent == NIL) root = i;

    // cout << "write root with i" << endl;

    cout << "Preorder" << endl;
    preParse(root);
    cout << endl;

    cout << "Inorder" << endl;
    inParse(root);
    cout << endl;

    cout << "Postorder" << endl;
    postParse(root);
    cout << endl;

    return 0;

}
