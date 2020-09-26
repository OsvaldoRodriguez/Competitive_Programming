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
const int N = 5e3 + 5;
const ll mod = 998244353;
const double E = 1e-7;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
vii G[N];
vector<tuple<int, int, ll>> L;
ll D1[N], D2[N];
void dijkstra(int node, ll *dis){
    dis[node] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0LL, node});
    while(sz(q)){
        int u = q.top().S;
        ll d = q.top().F;
        q.pop();
        if(d > dis[u])continue;
        fore(i, 0, sz(G[u])){
            int v = G[u][i].F;
            ll cost = G[u][i].S;
            if(dis[u] + cost < dis[v]){
                dis[v] = cost + dis[u];
                q.push({dis[v], v});
            }
        }        
    }
}
ll solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        D1[i] = D2[i] = 1e9;
    L.clear();
    for(int i = 0; i < n; i++)
        G[i].clear();
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;v--;
        L.pb({u, v, w});
        G[u].pb({v, w});
        G[v].pb({u, w});
    }
    dijkstra(0, D1);
    dijkstra(n - 1, D2);
    int mn = D1[n - 1];
    ll mx = 1e18;
    fore(i, 0, sz(L)){
        int u, v;
        ll w;
        tie(u, v, w) = L[i];
        ll cur = D1[v] + w + D2[u];
        if(cur > mn)
            mx = min(mx, cur);

        cur = D1[u] + w + D2[v];
        if(cur > mn)
            mx = min(mx, cur);
    }
    return mx;


}   

int main(){
    FIN;
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": " << solve() << '\n';
    }
    //EjecuteTime;
    return 0;
}  
