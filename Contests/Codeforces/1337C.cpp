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
const int N = 2 * 1e5 + 5;
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
vi G[N];
ll val[N];
int dfs(int u, int p, int depth){
    int sz = 1;
    val[u] += depth;
    for(int v : G[u]){
        if(v == p)continue;
        int len = dfs(v, u, depth + 1);
        sz += len;
        val[u] -= len;
    }
    return sz;
}
bool cmp(int a, int b){return a > b;}
int main(){
    //FL;
    FIN;
    int n, k;
    cin >> n >> k;
    fore(i, 1, n){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[v].pb(u);
        G[u].pb(v);
    }
    dfs(0, -1, 0);
    sort(val, val + n, cmp);
    ll ans = 0;
    for(int i = 0; i < k; i++)
        ans += val[i];
    cout << ans << '\n';
    EjecuteTime;
    return 0;
}       
