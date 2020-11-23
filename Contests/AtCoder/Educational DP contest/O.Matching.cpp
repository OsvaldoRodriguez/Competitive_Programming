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
#define db(x)           cout << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
void debug(){cout << endl;}
template<typename T, typename... Args>
void debug(T a, Args... args){cout << a << " "; debug(args...);}
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 22;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;
int v[N][N];
int n;
ll dp[N][1 << N];
ll f(int i, int mask){
    if(i == n)
        return __builtin_popcount(mask) == n;

    ll &ans = dp[i][mask];
    if(ans == -1){
        ans = 0;
        for(int j = 0; j < n; j++){
            if(v[j][i] && !(mask & (1 << j))){
                ans = (ans + f(i + 1, mask | (1 << j))) % mod;
            }
        }
    }
    return ans;
}

ll fast(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> v[i][j];
    cls(dp, -1);
    cout << f(0, 0) << '\n';
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
        cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
