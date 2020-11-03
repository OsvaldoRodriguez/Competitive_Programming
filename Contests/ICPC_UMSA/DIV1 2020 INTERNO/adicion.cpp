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
ll n;
ll dp[30][2][30][2];
vi v;
ll f(int i, bool flag, ll cnt, bool one){
    ll &ans = dp[i][flag][cnt][one];
    if(i == sz(v)){
        if(cnt == sz(v) && flag)
            return 1;
        return flag ? (1LL << cnt) : 0;
        
    }
    
    if(ans == -1){
        ans = 0;
        for(int j = 0; j < 2; j++)
            if(flag or j <= v[i])
                ans += f(i + 1, flag or (j < v[i]), cnt + (one && (j == 0) ? 1 : 0), one or (j == 1));    
    }
    return ans;
}

ll get(int x){
    v.clear();
    bool flag = 0;
    for(int i = 31; i >= 0; i--){
        if(!((1 << i) & x) && !flag)
            continue;
        flag = 1;
        v.pb(((1 << i) & x) ? 1 : 0);
    }
    if(x == 0)
        v.pb(0);
    cls(dp, -1);
    return f(0, 0, 0, 0);
}
void solve(){
    while(cin >> n)
        cout << get(n + 1) << '\n';
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
