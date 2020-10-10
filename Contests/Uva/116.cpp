#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
#define F           first
#define S           second
#define pb          push_back
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a)   for(int i = a; i >= 0; i--)
#define fori(i,m)   for(auto i = m.begin(); i != m.end(); i++) 
#define w(t)        while(t--)
#define sz(s)       int(s.size())
#define cls(a,car)  memset(a,car,sizeof (a))
#define db(x)       cerr << #x << " is " << x << '\n'
#define FI          freopen("input.txt", "r", stdin)
#define FO          freopen("output.txt", "w", stdout)
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int INF = 1e2;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll v[20][105];
ll dp[20][105];
int n, m;
ll f(int i, int j){
    if(j >= m)return 1e18;
    ll &ans = dp[i][j];
    if(j == m - 1)
        return ans = v[i][j];
    if(ans == -1){
        ans = 1e18;
        if(!i){
            ans = min(ans, f(i, j + 1) + v[i][j]);
            ans = min(ans, f((i + 1) % n, (j + 1) % m) + v[i][j]);
            ans = min(ans, f((i - 1 + n) % n, (j + 1) % m) + v[i][j]);
        }else if(i + 1 != n){
            ans = min(ans, f((i - 1 + n) % n, (j + 1) % m) + v[i][j]);
            ans = min(ans, f(i, j + 1) + v[i][j]);
            ans = min(ans, f((i + 1) % n, (j + 1) % m) + v[i][j]);
        }else{
            ans = min(ans, f((i + 1) % n, (j + 1) % m) + v[i][j]);
            ans = min(ans, f((i - 1 + n) % n, (j + 1) % m) + v[i][j]);
            ans = min(ans, f(i, j + 1) + v[i][j]);
        }
    }
    return ans;
}
vi cur;
void r(int i, int j){
    //if(j >= m)return ;
    if(j == m - 1){
        cur.pb(i);
        return;
    }
    ll ans = dp[i][j];
    if(!i){
        if(ans == dp[i][j + 1] + v[i][j]){
            cur.pb(i);
            r(i, j + 1);
            return;
        }
        if(ans == dp[(i + 1) % n][(j + 1) % m] + v[i][j]){
            cur.pb(i);
            r((i + 1) % n, (j + 1) % m);
            return;
        }
        if(ans == dp[(i - 1 + n) % n][(j + 1) % m] + v[i][j]){
            cur.pb(i);
            r((i - 1 + n) % n, (j + 1) % m);
            return;
        }
    }else if(i + 1 != n){
        if(ans == dp[(i - 1 + n) % n][(j + 1) % m] + v[i][j]){
            cur.pb(i);
            r((i - 1 + n) % n, (j + 1) % m);
            return;
        }
        if(ans == dp[i][j + 1] + v[i][j]){
            cur.pb(i);
            r(i, j + 1);
            return;
        }
        if(ans == dp[(i + 1) % n][(j + 1) % m] + v[i][j]){
            cur.pb(i);
            r((i + 1) % n, (j + 1) % m);
            return;
        }
    }else{
        if(ans == dp[(i + 1) % n][(j + 1) % m] + v[i][j]){
            cur.pb(i);
            r((i + 1) % n, (j + 1) % m);
            return;
        }
        if(ans == dp[(i - 1 + n) % n][(j + 1) % m] + v[i][j]){
            cur.pb(i);
            r((i - 1 + n) % n, (j + 1) % m);
            return;
        }
        if(ans == dp[i][j + 1] + v[i][j]){
            cur.pb(i);
            r(i, j + 1);
            return;
        }
    }
}
void solve(){
    while(cin >> n >> m){
        cls(dp, -1);
        cur.clear();
        fore(i, 0, n)
            fore(j, 0, m)
                cin >> v[i][j];
        ll ans = 2e18;
        int row = -1;
        fore(i, 0, n){
            cls(dp, -1);
            ll cur = f(i, 0);
            if(ans > cur){
                ans = cur;
                row = i;
            }
        }
        cls(dp, -1);
        ans = f(row, 0);
        r(row, 0);
        cout << cur[0] + 1;
        fore(i, 1, sz(cur))cout << ' ' << cur[i] + 1;cout << '\n';
        cout << ans << '\n';
    }
}
int main(){
    FIN;
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    //EjecuteTime;
    return 0;
}  
