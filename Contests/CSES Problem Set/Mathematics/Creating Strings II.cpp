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
ll F[N], IF[N];
ll fast(ll b, ll e){
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
    F[0] = 1;
    IF[0] = 1;
    for(ll i = 1; i < N; i++){
        F[i] = i * F[i - 1] % mod;
        IF[i] = fast(F[i], mod - 2);
    }
}

void solve(){
    string str;
    cin >> str;
    vector<int> frec(26);
    int n = str.size();
    ll ans = F[n];
    for(char i : str)
        frec[i - 'a']++;

    for(int i = 0; i < 26; i++){
        if(frec[i])
            ans = (ans * IF[frec[i]]) % mod;
    }
    cout << ans << "\n";


}

int main(){
    fastio;
    int t = 1;
    // cin >> t;
    preprocess();
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}   
// solo recorre en los bits encendidos
// O(bits_encendidos en mask)
// for(int x = mask; x; x &= (x - 1)){
//     int v = __builtin_ctz(x); // da la posicion donde esta 
// }
