#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
typedef long long ll;

int n, k;
ll T[MAX];

int capacity(ll P) {
    int i = 0;
    for(int j=0; j<k; j++) {
        ll s = 0;
        while(s+T[i] <= P) {
            s += T[i];
            i++;
            if(i == n) return n;
        }
    }
    return i;
}

int solve() {
    ll left = 0;
    ll right = 100000 * 100000;
    ll mid;
    while(right-left > 1) {
        mid = (left + right) / 2;
        int v = capacity(mid);
        if(v >= n) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> T[i];
    ll ans = solve();
    cout << ans << endl;
}