#include <bits/stdc++.h>

using namespace std;

// Criado por Guilherme Silveira
// Explicação em Buscar ou não buscar, eis a questão

int main() {
    string s;
    s = "a";
    for(char i='b';s.size() <= 1000;i++) {
        s = s + i + s;
    }
    int n;
    cin >> n;
    cout << s[n-1] << endl;
    return 0;
}