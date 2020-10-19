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
const int N = 1e6 + 5;
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

vector<int> adj[220];
int _time[2005], nodes[2008];
struct Dinic{
    struct Edge{
        int to, rev;ll cap, flow;
        Edge(int to, int rev, ll cap, ll flow):to(to), rev(rev), cap(cap), flow(flow){}
        void mostrar(){
            cout << "( " << to << ", " << rev << ", " << cap << ", " << flow << "), ";
        }
    };

    vector<vector<Edge>> G;
    vector<int> dis, block;
    int n, s, t;
    Dinic(int n, int s, int t):n(n), dis(n), block(n), s(s), t(t), G(n){}
    void addEdge(int u, int v, ll cap){
        G[u].pb((Edge){v, sz(G[v]), cap, 0});
        G[v].pb((Edge){u, sz(G[u]) - 1, 0, 0});
    }
    bool bfs(int node_max){
        fill(all(dis), -1);
        queue<int> q;q.push(s);
        dis[s] = 0;
        while(sz(q)){
            int u = q.front();q.pop();
            for(auto &e : G[u]){
                int v = e.to;
                if(_time[v] > 0 && v > node_max)continue;
                if(dis[v] == -1 && e.flow < e.cap){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        return dis[t] >= 0;
    }

    ll dfs(int u, ll f, int node_max){
        if(u == t)return f;
        for(auto &i = block[u]; i < sz(G[u]); i++){
            Edge &e = G[u][i];
            if(e.cap <= e.flow)continue;
            int v = e.to;
            if(_time[v] > 0 && v > node_max)continue;
            if(dis[v] == dis[u] + 1){
                ll cur = dfs(v, min(f, e.cap - e.flow), node_max);
                if(cur > 0){
                    e.flow += cur;
                    G[v][e.rev].flow -= cur;
                    return cur;
                }
            }
        }
        return 0;
    }

    ll max_flow(int node_max){
        ll flow = 0;
        while(bfs(node_max)){
            fill(all(block), 0);
            while(ll cur = dfs(s, LLONG_MAX, node_max))
                flow += cur;
        }
        return flow;
    }
};
void solve(){
    int len, n, x, s, t;
    cin >> n;
    unordered_set<int> cur;
    vi v;
    for(int i = 1; i <= n; i++){
        cin >> len;
        for(int j = 0; j < len; j++){
            cin >> x;
            adj[i].pb(x);
            cur.insert(x);
        }
    }
    for(auto i : cur)
        v.pb(i);
    sort(all(v));

    //mapeando nodes
    for(int i = 0; i < sz(v); i++)
        nodes[v[i]] = i + 1;

    s = 0;t = sz(v) + n + 1;
    Dinic F(sz(v) + n + 2, s, t);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < sz(adj[i]); j++){
            F.addEdge(nodes[adj[i][j]], i + sz(v), 1);
        }
    }
    for(int i = 0; i < sz(v); i++){
        _time[i + 1] = v[i];
        F.addEdge(s, i + 1, 1);
    }
    for(int i = 1; i <= n; i++){
        F.addEdge(sz(v) + i, t, 1);
    }
    int a = -1, b = sz(v), mid;
    
    while(b - a > 1){
        //clear flow

        for(int i = 0; i < sz(F.G); i++){
            for(int j = 0; j < sz(F.G[i]); j++)
                F.G[i][j].flow = 0;
        }

        mid = (a + b) >> 1;
        
        ll ans = F.max_flow(mid);
        if(ans == n)
            b = mid;
        else
            a = mid;
    }
    cout << _time[b] + 1 << '\n';
}
int main(){
    //FIN;
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    EjecuteTime;
    return 0;

}
