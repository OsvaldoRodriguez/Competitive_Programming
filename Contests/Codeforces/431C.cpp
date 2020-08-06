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
const int N = 1 * 1e2 + 50;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int n, k, d;
ll dp[N][2];
ll f(int len, bool flag){
    if(len > n)return 0;
    if(len == n)
        return flag ? 1 : 0;
    ll &ans = dp[len][flag];
    if(ans == -1){
        ans = 0;
        for(int i = 1; i <= k; i++)
            ans = (ans % mod + f(len + i, flag || i >= d) % mod) % mod;
    }
    return ans;
}
int main(){
    //FL;
    FIN;
    cin >> n >> k >> d;
    for(int len = n; len >= 0; len--){
        for(int flag = 0; flag < 2; flag++){
            ll &ans = dp[len][flag];
            if(len == n){
                ans = flag ? 1 : 0;
                continue;
            }
            for(int i = 1; i <= k; i++){
                if(len + i <= n)
                    ans = (ans + dp[len + i][flag || i >= d]) % mod;
            }
        }
    }
    cout << dp[0][0] << '\n';
    EjecuteTime;
    return 0;
}       
