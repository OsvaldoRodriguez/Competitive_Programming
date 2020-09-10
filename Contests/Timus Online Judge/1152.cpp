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
const int N = 20 + 5;
const ll mod = 1e8 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll dp[1 << 21];
ll cost[1 << 21];
int v[21];
int n;
ll f(int mask){
    if(__builtin_popcount(mask) == n)
        return 0;
    ll &ans = dp[mask];
    if(ans == -1){
        ans = 1e15;
        for(int i = 0; i < n; i++){
            int newmask = mask;
            for(int j = 0; j < 3; j++){
                newmask |= (1 << ((i + j) % n));
            }
            if(newmask != mask)
                ans = min(ans, f(newmask) + cost[newmask]);
        }
    }
    return ans;
}
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++)cin >> v[i];
    for(int i = 0; i < (1 << n); i++){
        ll cos = 0;
        for(int j = 0; j < n; j++){
            if((i & (1 << j)) == 0)
                cos += v[j];
        }
        cost[i] = cos;
    }
    for(int mask = (1 << n); mask >= 0; mask--){
        ll &ans = dp[mask];
        if(__builtin_popcount(mask) == n){
            ans = 0;
            continue;
        }
        ans = 1e12;
        for(int i = 0; i < n; i++){
            int newmask = mask;
            for(int j = 0; j < 3; j++)
                newmask |= (1 << ((i + j) % n));
            
            if(newmask != mask)
                ans = min(ans, dp[newmask] + cost[newmask]);
            
        }
    }
    cout << dp[0] << '\n';
}  
int main(){
    FIN;
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case " << i << " : ";
        solve(); 
    }
    //EjecuteTime;
    return 0;
}       
