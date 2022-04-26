#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e2 + 10;
const ll mod = 1e9 + 7;
ll n, m, d;
ll A[N];


ll go(ll sum, ll x){
    // en c++ los modulos pueden dar negativo
    // x = -1, m = 3
    // ademas si tengo -5 % 3 = -2
    // es decir solo le da una vuelta
    // para que el % de positivo hay que aproximar o x volerlo
    // positivo de la siguient manera  x + d * k (algun k que haga positivo el numero)
    // y luego sumar
    ll value = (abs(x) + d - 1) / d;
    ll cur = (x + (value) * d);
    return (sum + cur) % d;
}
ll dp[N][25][25];
ll f(int i, int elem, ll sum){
    if(i == n)
        return (elem == m and sum % d == 0);

    ll &ans = dp[i][elem][sum];
    if(ans == -1){
        ans = 0;
        if(elem < m)
            ans += f(i + 1, elem + 1, go(sum, A[i]));
        ans += f(i + 1, elem, sum);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;

    int t = 1;
    while(cin >> n >> q and (n or q)){
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        cout << "SET " << t++ << ":\n";
        int consultas = 1;
        while(q--){
            cin >> d >> m;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < 25; j++)
                    for(int k = 0; k < N; k++)
                        dp[i][j][k] = -1;
            cout << "QUERY " << consultas++ << ": "  << f(0, 0, 0) << '\n';
        }
    }

    
    return 0;

}
