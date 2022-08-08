#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 100;
const ll mod = 1e9 + 7;

ll fast(ll a, ll b, ll m){
    ll ans = 1;
    while(b){
        if(b & 1)
            ans = (ans % m * a % m) % m;
        b >>= 1;
        a = (a % m * a % m) % m;
    }
    return ans;
}
void solve(){  

    ll a, b, m; 
    while(cin >> a >> b >> m)
        cout << fast(a, b, m) << "\n";

    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
