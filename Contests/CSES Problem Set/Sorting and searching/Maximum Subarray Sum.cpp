#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
const ll mod = 1e9 + 7;
ll A[N];

ll f(int l, int m, int r){
    ll sum = 0;
    ll L = -1e18;
    for(int i = m; i >= l; i--){
        sum += A[i];
        L = max(L, sum);
    }

    sum = 0;
    ll R = -1e18;
    for(int i = m + 1; i <= r; i++){
        sum += A[i];
        R = max(R, sum);
    }

    return max({L, R, L + R});
}
ll go(int l, int r){
    if(l == r)
        return A[l];
    int m = (l + r) >> 1;

    return max({go(l, m), go(m + 1, r), f(l, m, r)});
}
void solve(){   
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];

    ll ans = go(0, n - 1);
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++)
        solve();
    return 0;
}
