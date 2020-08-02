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
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;
const double E = 1e-9;
bool ok;
int vis[N];
vi G[N];
int parent[N];
/*
n vetex
m edges
Complexity
Time:
    dfs -> O(n + m)
*/

void dfs(int u){
    vis[u] = 1;
    for(int i = 0; i < sz(G[u]); i++){
        int v = G[u][i];
        if(vis[v] == -1){
            parent[v] = u;
            dfs(v);
        }else if(parent[u] != v)
            ok = 1;
    }
}
int main(){
    //FL;
    FIN;
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        u--;v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    cls(vis, -1);
    ok = 0;
    for(int i = 0; i < n; i++)
        if(vis[i] == -1)
            dfs(i);
    cout << (ok ? "cycle" : "not cycle") << '\n';
    EjecuteTime;
    return 0;
}       