#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z;

  z = (Node *)malloc(sizeof(Node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL) {
    y = x;
    if(z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  z->parent = y;
  if(y == NIL) {
    root = z;
  } else {
    if(z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

void inorder(Node *u) {

}

/*
void inParse(int u) {
    // cout << "u = " << u << endl;
    if(u == NIL) return;

    inParse(T[u].left);

    cout << " " << u;

    inParse(T[u].right);
}
*/



void preorder(Node *u) {

}
/*
void preParse(int u) {
    // cout << "u = " << u << endl;
    if(u == NIL) return;

    cout << " " << u;

    preParse(T[u].left);
    preParse(T[u].right);
}
*/

int main() {
    int n, i, x;
    string = com;

    cin >> n;

    for(int i=0; i<n; i++) {

    }

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
