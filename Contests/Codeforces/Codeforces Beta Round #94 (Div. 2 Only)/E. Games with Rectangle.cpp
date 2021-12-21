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
ll dp[2010][2010];
ll f(int n, int k){
    ll &ans = dp[n][k];
    if(n == 0)return 0;
    if(n == k or k == 0)return 1;
    if(ans == -1){
        ans = dp[n][k] = (f(n - 1, k - 1) + f(n - 1, k)) % mod;
    }
    return ans;
}
ll get(int a, int b){
    return (dp[a - 2][2 * b] + dp[a - 2][2 * b - 1]) % mod; 
}
int main(){
    //FL;
    FIN;
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i < 2010; i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
        for(int j = 1; j < i; j++){
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
        }
    }   
    cout << (get(n, k) % mod * get(m, k) % mod) % mod;
    EjecuteTime;
    return 0;
}       
