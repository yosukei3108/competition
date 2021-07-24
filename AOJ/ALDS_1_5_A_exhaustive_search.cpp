#include <bits/stdc++.h>
using namespace std;

//Divide and Conquer

int n, A[50];

int solve(int i, int m) {
    if(m == 0) return 1;
    if(i >= n) return 0;
    
    int res = solve(i + 1, m) || solve(i + 1, m - A[i]);
    //cout << "now, i = " << i << ", m = " << m << endl;
    
    return res;
}

int main() {
    int q, M, i;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++) scanf("%d", &A[i]);
    
    scanf("%d", &q);
    
    for(i=0; i<q; i++) {
        scanf("%d", &M);
        //cout << "M = " << M << ", invoke solve(0, " << M << ")" << endl;
        if(solve(0, M)) printf("yes\n");
        else printf("no\n");
    }
    
    return 0;

}
