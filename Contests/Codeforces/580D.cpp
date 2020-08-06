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
#define FL          freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int add(int a, int b){return  a + b > mod ? a + b - mod : a + b;}
int mul(int a, int b){return a * b >= mod ? a * b % mod : a * b;}  
int cost[20][20];
int v[20];
int n, m, k;
ll dp[20][1 << 20];
ll f(int last, int mask){
    if(__builtin_popcount(mask) == m)
        return 0;
    ll &ans = dp[last][mask];
    if(ans == -1){
        ans = 0;
        fore(i, 0, n){
            if(!(mask >> i & 1))
                ans = max(ans, f(i, mask ^ (1 << i)) + v[i] + cost[last][i]);
        }
    }
    return ans;
}
int main(){
    //FL;
    FIN;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    w(k){
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        cost[u][v] = c;
    }
    for(int mask = (1 << n) - 1; mask >= 0; mask--){
        for(int last = n - 1; last >= 0; last--){
            ll &ans = dp[last][mask];
            if(__builtin_popcount(mask) == m){
                ans = 0;
                continue;
            }
            ans = 0;
            for(int i = 0; i < n; i++){
                if(!(mask >> i & 1))
                    ans = max(ans, dp[i][mask ^ (1 << i)] + v[i] + cost[last][i]);
            }
        }
    }
    ll cur = 0;
    for(int i = 0; i < n; i++)
        cur = max(cur, dp[i][1 << i] + v[i]);
    cout << cur << '\n';
    EjecuteTime;
    return 0;
}       
