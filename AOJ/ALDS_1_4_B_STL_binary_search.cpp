#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int A[1000006];
int n;

int main(void){
    cin >> n;
    for (int i=0; i<n; i++) scanf("%d", &A[i]);
    
    int q, k;
    int sum = 0;
    cin >> q;

    for (int i=0; i<q; i++) {
        scanf("%d", &k);
        if (*lower_bound(A, A + n, k) == k) sum++;
    }
    printf("%d\n", sum);
    
    return 0;

}
