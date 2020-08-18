// A
// B

// A / B = ponto...

// se tem representacao finita ==> 0.12345678
//                                   existe um numero de casas depois da virgula FINITO
// A / B * 10 ^8 = 12345678 inteiro

// tem que existir k tal que
// A / B * C ^ k = numero inteiro

// queremos achar o menor valor de C que faz aquilo ser verdadeiro

// 2 / 4
// 1 / 2

// 1. REDUZIR A FRACAO
// A / B * (C ^ k) = numero inteiro
// (A * (C ^k)) / B = numero inteiro

// os fatores de B tem que estar presentes em C

// B=3x5 ===> C=15
// B=3^2*5 ===> C=45? C=15.... C=15 eh a solucao
// quais sao os fatores de B?

#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ll a, b;
    cin >> a >> b;
    b /= __gcd(a,b);

    // forma reduzida da divisao

    // quero saber os fatores de b
    ll resto = b;

    ll resposta = 1;
    for(ll i = 2; i * i * i <= resto; i++) {
        if(resto % i == 0) {
            resposta *= i;
            while(resto %i == 0) resto /= i;
        }
    }

    // com esse if nao passa!!!!
    // if(resto == 1) {
// 
    // } else {
        ll raiz = sqrt(resto);
        if(raiz * raiz == resto) {
            resposta *= raiz;
        } else {
            resposta *= resto;
        }
    // }

    cout << max<ll>(2, resposta) << endl;

    return 0;
}
