#include <bits/stdc++.h>

using namespace std;

// 1 ate 9
// 1+9=10
// 2+8=10

// +--+
// +-+--+-+

int main() {
    int n;
    scanf("%d", &n);

    bool has_three = false;

    if(n & 3) {
        n -= 3;
        has_three= true;
    }

    if(n & 1) {
        printf("-1\n");
        return 0;
    }
    if(n & 2) {
        printf("-1\n");
        return 0;
    }

    if(has_three) {
        printf("++-");
    }

    int k = n / 4;
    while(k--) printf("+-");
    k = n / 4;
    while(k--) printf("-+");
    printf("\n");

    return 0;
}