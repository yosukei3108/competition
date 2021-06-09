#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int q, x;
    char com[20];

    list<int> l;
    scanf("%d", &q);

    for (int i=0; i<q; i++) {
        scanf("%s", com);
        
        if (com[0] == 'i') {
            scanf("%d", &x);
            l.push_front(x);
        } else if (com[6] == 'L') {
            l.pop_back();
        } else if (com[6] == 'F') {
            l.pop_front();
        } else if (com[0] == 'd') {
            scanf("%d", &x);
            for (list<int>::iterator it=l.begin(); it!=l.end(); it++) {
                if (*it==x) {
                    l.erase(it);
                    break;
                }
            }
        }
    }
    int i = 0;
    for (list<int>::iterator it = l.begin(); it!=l.end(); it++) {
        if (i++) printf(" ");
        printf("%d", *it);
    }
    
    printf("\n");

    return 0;
}
