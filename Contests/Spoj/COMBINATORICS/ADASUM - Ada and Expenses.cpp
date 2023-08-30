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
const int N = 2e6 + 5;
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
ll ACC[N];

void solve(){
    string str;
    cin >> str;
    int n = str.size();
    vector<ll> acc(n);
    acc[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--){
        acc[i] = (acc[i + 1] * 10LL) % mod;
    }    
    for(int i = n - 2; i >= 0; i--){
        acc[i] = (acc[i] + acc[i + 1]) % mod;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll cur = (acc[i] * (str[i] - '0')) % mod;
        cur = (cur * ((ll)i + 1)) % mod;
        ans = (ans + cur) % mod;
    }
    cout << ans << "\n";
}

int main(){
    fastio;
    int t = 1;
    // cin >> t;
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
