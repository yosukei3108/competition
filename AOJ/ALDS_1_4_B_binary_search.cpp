#include <bits/stdc++.h>
using namespace std;

int A[1000006], n;

int binary_search(int key) {
    int left = 0;
    int right = n;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (key == A[mid]) return 1;
        if (key > A[mid]) left = mid + 1;
        else right = mid;
    }
    return 0;
}

int main(void){
    int i, q, k;
    int sum = 0;
    
    scanf("%d", &n);
    for (i=0; i<n; i++) scanf("%d", &A[i]);
    
    scanf("%d", &q);
    for (i=0; i<q; i++) {
        scanf("%d", &k);
        if (binary_search(k)) sum++;
    }
    printf("%d\n", sum);
    
    return 0;

}
