#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> valores;
    while(n--) {
        long long p;
        cin >> p;
        // cout << p << endl;
        valores.push_back(p);
    }
    sort(valores.begin(),valores.end());

    long long consigo = 0;
    long long atual = 1;
    for(auto v : valores) {
        //cout << v << " " << atual << " " << consigo << endl;
        if(v == atual) {
            consigo += v;
        } else if(v > atual) {
            // atual = 1
            // consigo = 2
            // v = 2

            // 16+1
            // 17
            if(consigo + 1 < v) {
                cout << (consigo + 1) << endl;
                return 0;
            }

            atual = v;
            consigo += v;
        } else {
            // nao acontece
        }
        // cout << v << endl;
    }
     //  cout<< " " << atual << " " << consigo << endl;
     cout << (consigo + 1)<< endl;
    return 0;
}

// 3
// 2 1 10000000000


// 1 2 10000000000

// 1 2
// 1 1 2
// 1 1 1 1 1 2 2
// 5 ok
// 9?
// 1 1 1 1 1 2 2 4
// 1? => 1
// 1 1 => 2