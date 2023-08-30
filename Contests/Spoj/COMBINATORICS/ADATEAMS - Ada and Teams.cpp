#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define fastio      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll          long long
#define all(_)      (_).begin(), (_).end()
#define sz(_)       int(_.size())
#define pii         pair<int, int>
#define pll         pair<ll, ll>
using namespace std;
// using namespace __gnu_pbds; // ordered_set
const int N = 1e6 + 5;
ll mod = 1e9 + 7;
const double eps = 1e-9;
// less<type>  prioridad menor
// greater<type>  prioridad mayor
// add equal<type>  less_equal or greater_equal // multiset
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int di[] = {1, 0, 0, -1}, dj[] = {0, -1, 1, 0};
// string dir = "DLRU";
//**********************************************************************
// Later or Sooner discipline overcomes talent, come on, I can do it.
ll F[N];
ll IF[N];
ll f(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e & 1)
            ans = (ans * b) % mod;
        e >>= 1;
        b = (b * b) % mod;
    }
    return ans;
}
void preprocess(){
    F[0] = IF[0] = 1;
    for(ll i = 1; i < N; i++){
        F[i] = (F[i - 1] * i) % mod;
        IF[i] = f(F[i], mod - 2);
    }
}

ll comb(ll n, ll k){
    ll ans = (F[n] * IF[k]) % mod;
    ans = (ans * IF[n - k]) % mod;
    return ans;
}
void solve(ll N, ll A, ll B, ll D){
    // la solucion es 
    /*
    ( N ) * ( B )^A
    ( A ) * ( D )

    hay A tomados de N formas de esgoger colegios
    y D tomador de B de escoger estudiantes por grupo, pero como
    se esta escogiendo A grupos y sucede al mismo tiempo
    por el principio de la multiplicacion se escoge A veces
    */

    

    ll ans = comb(N, A);
    ll cur = f(comb(B, D), A);
    cout << (ans * cur) % mod << "\n";
}

int main(){
    fastio;
    int t = 1;
    // cin >> t;
    preprocess();
    ll N, A, B, D;
    while(cin >> N >> A >> B >> D)
        solve(N, A, B, D);
    
    return 0;
}   
// solo recorre en los bits encendidos
// O(bits_encendidos en mask)
// for(int x = mask; x; x &= (x - 1)){
//     int v = __builtin_ctz(x); // da la posicion donde esta 
// }
