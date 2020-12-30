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
const int N = 2e5 + 10;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;
int n, t, w;
int dp[35][1111];
int d[35], g[35];
int f(int i, int T){
    if(T < 0)return -1e9;
    if(i == n)
        return 0;
    int &ans = dp[i][T];
    if(ans == -1){
        ans = 0;
        ans = max(ans, f(i + 1, T));
        ans = max(ans, f(i + 1, T - w * d[i] - 2 * w * d[i]) + g[i]);
    }
    return ans;
}
vii cur;

void build(int i, int T){
    if(T < 0)return;
    if(i == n)return;
    int ans = dp[i][T];
    if(ans == f(i + 1, T)){
        build(i + 1, T);
        return;
    }
    if(ans == f(i + 1, T - w * d[i] - 2 * w * d[i]) + g[i]){
        cur.pb(ii(d[i], g[i]));
        build(i + 1, T - w * d[i] - 2 * w * d[i]);
        return;
    }
}
void solve(){
    int test = 1;
    while(cin >> t >> w >> n){
        cur.clear();
        for(int i = 0; i < n; i++)
            cin >> d[i] >> g[i];
        
        cls(dp, -1);

        if(test > 1)
            cout << '\n';
        test++;
        cout << f(0, t) << '\n';
        build(0, t);
        cout << sz(cur) << '\n';
        for(auto i : cur)cout << i.F << " " << i.S << '\n';

    }
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
    for(int i = 1; i <= t; i++){
        solve();
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
