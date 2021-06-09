#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, q, t;
    string name;

    queue<pair<string, int> > Q;

    cin >> n >> q;

qro 
    cin >> n >> quantum;

    for (i=1; i<=n; i++) cin >> q[i].name >> q[i].t;

    head = 1; tail = n + 1;

    while (head != tail) {
        u = dequeue();
        c = min(quantum, u.t);
        u.t -= c;
        elapsed += c;
        if (u.t>0) enqueue(u);
        else cout << u.name << " " << elapsed << endl;

    }
    return 0;
}
