#include <bits/stdc++.h>
#define ii              pair<int,int>
#define F               first
#define S               second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define rall(x)         (x).rbegin(),(x).rend()
#define fore(i, a, b)   for(int i = a; i < b; i += 1)
#define forr(i, a)      for(int i = a; i >= 0; i--)
#define sz(s)           int(s.size())
#define cls(a,car)      memset(a,car,sizeof (a))
#define db(x)           cerr << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;

ll BIT[2][N];
int n;
void update(int t, int pos, int val){
    for(int i = pos; i <= n; i += i&-i)
        BIT[t][i] += val;
}
ll get(int t, int pos){
    ll ans = 0;
    for(int i = pos; i >= 1; i -= i&-i)
        ans += BIT[t][i];
    return ans;
}
ll get(int t, int l, int r){
    if(r > n or l < 0)return 0;
    if(l == 0)
        return get(t, r);
    return get(t, r) - get(t, l - 1);
}
void solve(){
    cin >> n;
    vi v(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        update(1, v[i], 1);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        update(1, v[i], -1);
        update(0, v[i], 1);
        ans += get(0, v[i] + 1, n) * get(1, 1, v[i] - 1);
    }
    cout << ans << '\n';

}
int main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++)
        solve();

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
