#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
const int N = 1e5 + 50;
int A[N], ST[20][N];
int n;

/*
Complextity
Space: 
    build   ->  O(log(n) * n)
Time:
    build   ->  O(log (n) * n)
    query   -> O(1)
*/
int f(int a, int b){return __gcd(a, b);}
void build(){
    for(int i = 0; i < n; i++)
        ST[0][i] = A[i];
    for(int i = 1; (1 << i) <= n; i++){// i <= log_2(n)
        for(int j = 0; j < n - (1 << i) + 1; j++){
            int a = j;
            int b = j + (1 << (i - 1));
            ST[i][j] = f(ST[i - 1][a], ST[i - 1][b]);
        }
    }
}
int query(int I, int J){
    int a = 31 - __builtin_clz(J - I + 1);
    int x = ST[a][I];
    int y = ST[a][J - (1 << a) + 1];
    return f(x, y);
}
int main(){
    int q;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    int l, r;
    build();
    
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << query(l - 1, r - 1) << '\n'; // index 0
    }   
    return 0;
}       
