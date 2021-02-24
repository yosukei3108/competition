#include <bits/stdc++.h>
using namespace std;
#define N 1000000

int arr[N];

void normal(){
    for(int i=1; i<=N; i++){
        int count = 0;
        for(int j=1; j<=i; j++){
            if(i % j == 0){
                count++;
            }
            if(count > 2){
                break;
            }
        }
        if(count == 2){
            //cout << i << endl;
        }
    }
}

void Eratosthenes(){
    
    for(int i=0; i<N; i++){
        arr[i] = 1;
    }
    arr[0] = 0;
    arr[1] = 0;
    
    for(int i=2; i*i<N; i++){
        if(arr[i]){
            for(int j=0; i*(j+2)<N; j++){
                arr[i * (j + 2)] = 0;
            }
        }
    }
    
    for(int i=0; i<N; i++){
        if(arr[i]){
            //cout << i << endl;
        }
    }
}




int main(int argc, char const *argv[]){
    clock_t start = clock();
    normal();
    clock_t end = clock();
    cout << "素朴な素数の列挙" << endl;
    cout << setprecision(15) << (double)(end - start) / CLOCKS_PER_SEC << endl;
    
    cout << endl;
    
    cout << "エラトステネスの篩" << endl;
    start = clock();
    Eratosthenes();
    end = clock();
    cout << setprecision(15) << (double)(end - start) / CLOCKS_PER_SEC << endl;
    
    return 0;

}
