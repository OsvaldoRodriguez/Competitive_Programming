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
const int N = 1 * 1e4 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int v[N];
int n;
ll dp[2][2];
ll f(int i, int last){
    if(i == n)return 0;
    ll &ans = dp[i][last];
    if(ans == -1){
        ans = 0;
        if(last)
            ans = max(ans, f(i + 1, 0));
        else{
            ans = max(ans, f(i + 1, 1) + v[i]);
            ans = max(ans, f(i + 1, 0));
        }
    }
    return ans;
 
}
int main(){
    //FL;
    FIN;
    int t;
    cin >> t;
    for(int j = 1; j <= t; j++){
        cin >> n;
        for(int i = 0; i < n; i++)cin >> v[i];
        cls(dp, 0);
        for(int i = n; i >= 0; i--){
            for(int last = 0; last < 2; last++){
                ll &ans = dp[i & 1][last];
                if(i == n){
                    ans = 0;
                    continue;
                }
                if(last)
                    ans = max(ans, dp[(i + 1) & 1][0]);
                else{
                    ans = max(ans, dp[(i + 1) & 1][1] + v[i]);
                    ans = max(ans, dp[(i + 1) & 1][0]);
                }
            }
        }
        cout << "Case " << j << ": ";
        cout << max(dp[0][1], dp[0][0]) << '\n';
    }
    EjecuteTime;
    return 0;
}        
