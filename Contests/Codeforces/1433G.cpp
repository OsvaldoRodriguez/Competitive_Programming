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
const int N = 1e3 + 5;
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
//105470163083
//100000000223257 primos
//1000000000318157
vector<ii> G[N], edges, courier;
int dis[N][N]; 
int n, m, k;
// 0 a to b
// 1 b to a
void dijkstra(int node){
    dis[node][node] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, node});
    while(sz(q)){
        int u = q.top().S;
        int d = q.top().F;
        q.pop();
        if(dis[node][u] != d)continue;
        for(int i = 0; i < sz(G[u]); i++){
            int v = G[u][i].F;
            int cost = G[u][i].S;
            if(dis[node][u] + cost < dis[node][v]){
                dis[node][v] = dis[node][u] + cost;
                q.push({dis[node][v], v});
            }
        }
    }
}
void solve(){
    int u, v, w;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].pb({v, w});
        G[v].pb({u, w});
        edges.pb({u, v});
    }
    for(int i = 0; i < k; i++){
        cin >> u >> v;
        u--;
        v--;
        courier.pb({u, v});
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dis[i][j] = 1e9;
    for(int i = 0; i < n; i++)
        dijkstra(i);
    

    int ans = 1e9;
    for(int i = 0; i < sz(edges); i++){
        int aux = 0;
        for(int j = 0; j < sz(courier); j++){
            int cur = dis[courier[j].F][edges[i].F] + dis[courier[j].S][edges[i].S];
            cur = min(cur, dis[courier[j].F][edges[i].S] + dis[courier[j].S][edges[i].F]);
            cur = min(cur, dis[courier[j].F][courier[j].S]);
            aux += cur;
        }
        ans = min(ans, aux);
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
