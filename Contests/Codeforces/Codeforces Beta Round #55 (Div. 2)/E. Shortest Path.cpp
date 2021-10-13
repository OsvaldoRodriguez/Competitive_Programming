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
const int N = 3e3 + 5;
const ll mod = 998244353;
const double E = 1e-7;
//int dx[] = {0, -1}, dy[] = {-1, 0};
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
vi G[N];
int dis[N][N];
ii P[N][N];
int n, m, k;
set<tuple<int, int, int>> s;
void bfs(int node = 0){
    dis[node][node] = 0;
    queue<ii> q;
    q.push({node, node});
    while(sz(q)){
        int par = q.front().F;
        int u = q.front().S;
        q.pop();
        if(u == n - 1){
            cout << dis[par][u] << '\n';
            vi ans;
            
            ans.pb(n - 1);
            while(par != 0 or u != 0){
                ans.pb(P[par][u].S);
                int aux = P[par][u].F;
                u = P[par][u].S;
                par = aux;
            }
            reverse(all(ans));
            for(auto i : ans)cout << i + 1 << ' ';cout << '\n';
            return;
        }
        fore(i, 0, sz(G[u])){
            int v = G[u][i];
            if(s.count({par, u, v}))continue;
            if(dis[par][u] + 1 < dis[u][v]){
                dis[u][v] = dis[par][u] + 1;
                P[u][v] = {par, u};
                q.push({u, v});
            }
        }

    }
    cout << -1 << '\n';
}
void solve(){
    cin >> n >> m >> k;
    fore(i, 0, m){
        int u, v;
        cin >> u >> v;
        u--;v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dis[i][j] = 1e9;
    fore(i, 0, k){
        int u, v, w;
        cin >> u >> v >> w;
        u--;v--;w--;
        s.insert({u, v, w});
    }
    bfs();
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
