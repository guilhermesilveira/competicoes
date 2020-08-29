#include <bits/stdc++.h>

using namespace std;

// Criado por Guilherme Silveira
// A gravar https://codeforces.com/gym/101879/problem/B

#define MAXN 2006
int kz[MAXN];

bool testa(int n, int k) {
    int restos[MAXN] = {0};
    for(int j=0;j<n;j++) {
        int key = kz[j] % k;
        restos[key]++;
        //cout << k << " " << kz[j] << ">>" << restos[key] << endl;
        if(restos[key] > (n/k)) return false;
    }
    return true;
}
int main() {
    int n;

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> kz[i];
    }

    for(int k=2;k<=n;k++) {
       // cout << n << endl;
        if(n % k == 0 && testa(n,k)) {
            cout << (k) << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    return 0;
}