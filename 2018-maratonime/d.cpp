#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 1000005;
typedef pair<int,int> point;
typedef pair<point, char> event;

// solução dos juizes
// A escrever e gravar em breve :) https://codeforces.com/gym/101879/problem/D


event E[MAXN];
int N;

int solve(int Rb, int Rw){
	int best = max(Rb, Rw);
	sort( E, E + N ); 
	int Lb, Lw;
	
	int i = 0;
	Lw = Lb = 0;
	for ( ; i < N; ){
		int x = E[i].first.first;	
		while ( i < N && x == E[i].first.first ){
			if ( E[i].second == 'b' )
				Lb++, Rb--;
			else 
				Lw++, Rw--;
			++i;
		}
		//Take the best
		best = max( best, max( Lw + Rb, Lb + Rw ) ); 
	}
	return best;
}

int main(){
	int x, y;
	int b, w;
	char t;

	scanf("%d", &N);
	// soma os totais	
	b = w = 0;
	for ( int i=0; i < N; ++i ){
		scanf("%d %d %c", &x, &y, &t);
		// armazena todos os pontos
		E[i] = event( point(x,y) , t );		
		// soma os totais	
		if ( t == 'b' ) b++;
		else w++;
	}

	int res = solve(b,w); 

	// rotate the plane 45 degrees
	for ( int i=0; i < N; ++i )
		swap( E[i].first.first, E[i].first.second );
	
	res = max( res, solve(b,w) );
	
	printf("%d\n", res);
	return 0;
}
