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
const ll mod = 998244353;
const double E = 1e-7;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll F[N], INV[N], FINV[N];
ll C(ll n, ll k){
    if(n < k)return 0;
    return ((F[n] * FINV[k]) % mod * FINV[n - k]) % mod;
}
void solve(){
    int n, k;
    vii v;
    cin >> n >> k;

    F[0] = 1;
    for(int i = 1; i < n; i++)
        F[i] = (F[i - 1] * i) % mod;
    
    INV[1] = 1;
    for(int i = 2; i < n; i++)
        INV[i] = (mod - ((ll)(mod / i) * INV[mod % i]) % mod + mod) % mod;

    FINV[0] = 1;
    for(int i = 1; i < n; i++)
        FINV[i] = (FINV[i - 1] * INV[i]) % mod;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.pb({x, -1});
        v.pb({y, 1});
    }
    sort(all(v));
    ll ans = 0;
    int cur = 0;
    for(int i = 0; i < sz(v); i++){
        if(v[i].S == -1)
            cur++;
        else{
            cur--;
            if(cur >= k - 1)
                ans = (ans + C(cur, k - 1)) % mod;
        }
    }
    cout << ans << '\n';
}   
int main(){
    FIN;
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve(); 
    }
    EjecuteTime;
    return 0;
}  
