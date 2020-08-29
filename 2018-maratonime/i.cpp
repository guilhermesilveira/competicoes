#include <bits/stdc++.h>
using namespace std;

#define pb push_back
deque<pair<char, char>> sol;
typedef pair<char, char> pcc;

// solução dos juizes
// A escrever e gravar em breve :) https://codeforces.com/gym/101879/problem/I


void solve(int n, char a, char b, char c) {
	assert(n > 0);
	if(n == 1) {
		sol.pb(pcc(a, c));
		return;
	}
    // resolve um jeito pra enviar todos os n-1 de a pra b
	solve(n - 1, a, c, b);
    // maravilha, posso enviar de a para c
	sol.pb(pcc(a, c));
    // agora move todo mundo de b para c
	solve(n - 1, b, a, c);
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
    // 2 ^n - 1 exatos moves
	if(k < (1 << n) - 1) puts("N");
	else {
		puts("Y");
		solve(n, 'A', 'B', 'C');
		assert(sol.size() == ((1 << n) - 1));

        // transforma um passo em dois passos
		while(sol.size() < k) {
            // pega o primeiro
			pcc fs = sol.front(); sol.pop_front();


			char from = fs.first; char to = fs.second;
			
            // c eh o que sobra!!!
            char c = 'A' + 'B' + 'C' - from - to;
            
			sol.push_front(pcc(c, to));
			sol.push_front(pcc(from, c));
		}
		for(pcc p : sol)
			printf("%c %c\n", p.first, p.second);
	}
}

