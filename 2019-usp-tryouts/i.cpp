#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

// Criado por Guilherme Silveira
// Explicação em https://www.youtube.com/watch?v=Ujr1eo4CvrI

using namespace std;

bool comparator(pair<long long, long long> &a, pair<long long, long long> &b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> valores;
    long long p, f;
    for(int i=0;i<n;i++) {
        cin >> p >> f;
        valores.push_back(pair<long long, long long>(p, f));
        // cout << p << f << endl;
    }
    sort(valores.begin(), valores.end(), comparator);
    long long soma = 0;
    long long maior_soma = valores[0].first - valores[0].second;
    for(auto valor : valores) {
        soma += valor.first;
        long long se_para = soma - valor.second;
        if(se_para > maior_soma) {
            maior_soma = se_para;
        }
       //cout << valor.first << " " << valor.second << " " << maior_soma << endl;
    }
    cout << maior_soma << endl;
    return 0;
}