/*
initialize()
    head = tail = 0

isEmpty()
    return head == tail

isFull()
    return head == (tail + 1) % MAX

enqueue(x)
    if isFull()
        error: queue overflow
    Q[tail] = x
    if tail + 1 == MAX
        tail = 0
    else
        tail++

dequeue()
    if isEmpty()
        error: queue underflow
    x = Q[head]
    if head + 1 == MAX
        head = 0
    else
        head++
    return x
*/

#include <bits/stdc++.h>
using namespace std;
#define LEN 100005

typedef struct process {
    string name;
    int t;
} Proc;

Proc q[LEN];
int head, tail, n;

void enqueue(Proc x){
    q[tail] = x;
    tail = (tail + 1) % LEN;
}

Proc dequeue() {
    Proc x = q[head];
    head = (head + 1) % LEN;
    return x;
}

int main() {
    int elapsed = 0, c;
    int i, quantum;
    Proc u;
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
