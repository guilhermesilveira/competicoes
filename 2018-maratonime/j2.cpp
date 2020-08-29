#include <bits/stdc++.h>

using namespace std;

// Criado por Guilherme Silveira
// Explicação em Buscar ou não buscar, eis a questão


int s[30];

// a 0
// aba 1
// abacaba (2, 3) (2,7)


char solve(int profundidade, int enesima) {
    if(enesima <= s[profundidade-1]) {
        return solve(profundidade - 1, enesima);
    }
    if(enesima == s[profundidade-1] + 1) {
        return ('a' + profundidade);
    }
    return solve(profundidade - 1, enesima - s[profundidade-1] - 1);
}


int main() {

    s[0] = 1;
    for(int i=1;i<=26;i++) {
        s[i] = s[i-1] + 1 + s[i-1]; 
    }

    int n;
    scanf("%d", &n);
    cout << solve(25, n) << endl;

    return 0;
}