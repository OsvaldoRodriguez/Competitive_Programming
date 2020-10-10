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
int cost[N];
vi G[N], Ginv[N];
int id[N], vis[N];
int ways[N];
int cant[N];
int scc = 1;
stack<int> st;
void dfs(int u){
    vis[u] = 1;
    for(int v : Ginv[u])
        if(vis[v] == -1)
            dfs(v);
    st.push(u);
}
void dfs2(int u, int comp){
    vis[u] = 1;
    id[u] = comp;
    for(int v : G[u]){
        if(vis[v] == -1)
            dfs2(v, comp);
    }
}
void solve(){
    int n;
    cin >> n;
    fore(i, 1, n + 1){
        cin >> cost[i];
        ways[i] = 2e9;
    }
    int m;
    cin >> m;
    int u, v;
    while(m--){
        cin >> u >> v;
        G[u].pb(v);
        Ginv[v].pb(u);
    }
    cls(vis, -1);
    fore(i, 1, n + 1)
        if(vis[i] == -1)
            dfs(i);
    cls(vis, -1);
    scc = 1;
    while(sz(st)){
        int u = st.top();st.pop();
        if(vis[u] == -1){
            dfs2(u, scc);
            scc++;
        }
    }
    fore(i, 1, n + 1){
        if(ways[id[i]] > cost[i]){
            ways[id[i]] = cost[i];
        }
    }
    fore(i, 1, n + 1){
        if(ways[id[i]] == cost[i])
            cant[id[i]]++;
    }
    ll ans = 0;
    ll _ways = 1;
    fore(i, 1, scc){
        ans += 1LL * ways[i];
        _ways = (_ways * 1LL * cant[i]) % mod;
    }
    cout << ans << " " << _ways << '\n';
}
int main(){
    //FIN;
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    //EjecuteTime;
    return 0;
}  
