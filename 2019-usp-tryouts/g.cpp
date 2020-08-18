
// joao
//   ^
// antonio

// joao
//   ^
// carlos

// joao
//   ^
// guilherme
// path compression

// parent[guilherme] = joao 

#include "bits/stdc++.h"

using namespace std;

#define MAX 100005

int parent[MAX];
int power[MAX];

int find_root(int q) {
    if(parent[q] == q) {
        return q;
    }

    int p = parent[q];
    int parent_root = find_root(p);

    power[q] = min(power[q], power[p]);
    parent[q] = parent_root;
    return parent_root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // cin >> n >> m;
    for(int i=0;i<n;i++) {
        scanf("%d", &power[i]);
        // cin >> power[i];
        parent[i] = i;
    }
    while(m--) {
        char op;
        // cin >> op;
        scanf(" %c", &op);
        if(op=='+') {
            int i,j;
            scanf("%d %d", &i, &j);
            // cin >> i >> j;
            i--;j--;
            parent[j] = i;
        } else if(op=='?') {
            int q;
            // cin >> q;
            scanf("%d", &q);
            q--;
            int raiz = find_root(q);
            //for(int k=0;k<n;k++) cout << parent[k] << " ";
            //cout << endl;
            //cout << "analisa " << q << " " << raiz << endl;
            printf("%d\n", power[q]);
            // cout << power[q] << endl;
        } else {
            int j = 10 / 0;
            cout << j << endl;
        }
    }
    return 0;
}









