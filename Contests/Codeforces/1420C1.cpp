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
const int N = 3e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int v[N];
int n, q;
ll dp[N][3][2];
ll f(int i, int beg, int sig){
    if(i == n)return 0;
    ll &ans = dp[i][beg][sig];
    if(ans == -1){
        ans = 0;
        if(beg == 0){
            ans = max(ans, f(i + 1, beg, sig));
            ans = max(ans, f(i + 1, 1, !beg) + (sig == 0 ? 1 : -1) * v[i]);
        }else if(beg == 1){
            ans = max(ans, f(i + 1, beg, sig));
            ans = max(ans, f(i + 1, beg, !sig) + (sig == 0 ? 1 : -1) * v[i]);
            ans = max(ans, f(i + 1, 2, sig));
        }else
            ans = max(ans, f(i + 1, beg, sig));
    }
    return ans;
}
void solve(){
    cin >> n >> q;
    for(int i = 0; i < n; i++)cin >> v[i];
    cls(dp, -1);
    cout << f(0, 0, 0) << '\n';
        
}   
int main(){
    FIN;
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(); 
    }
    EjecuteTime;
    return 0;
}  
