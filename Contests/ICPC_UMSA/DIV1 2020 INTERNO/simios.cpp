#include <bits/stdc++.h>
#define ii              pair<int,int>
#define F               first
#define S               second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define rall(x)         (x).rbegin(),(x).rend()
#define fore(i, a, b)   for(int i = a; i < b; i += 1)
#define forr(i, a)      for(int i = a; i >= 0; i--)
#define sz(s)           int(s.size())
#define cls(a,car)      memset(a,car,sizeof (a))
#define db(x)           cerr << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;
struct Dinic{
    struct Edge{
        int to, rev;
        ll cap, flow;
        Edge(int to, int rev, ll cap, ll flow): to(to), rev(rev), cap(cap), flow(flow){}
        void mostrar(){
            cout << "( " << to << ", " << rev << ", " << cap << ", " << flow << ") ";
        }
    };
    vector<vector<Edge>> G;
    vector<int> dis, block;
    int n, s, t;
    Dinic(){}
    Dinic(int n, int s, int t): n(n), dis(n), block(n), s(s), t(t), G(n){}
    void addEdge(int u, int v, ll cap){
        G[u].pb((Edge){v, sz(G[v]), cap, 0});
        G[v].pb((Edge){u, sz(G[u]) - 1, 0, 0});
    }
    bool bfs(){
        fill(all(dis), -1);
        dis[s] = 0;
        queue<int> q;q.push(s);
        while(sz(q)){
            int u = q.front();q.pop();
            for(auto &e: G[u]){
                int v = e.to;
                if(dis[v] == -1 && e.flow < e.cap){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        return dis[t] >= 0;
    }
    ll dfs(int u, ll f){
        if(u == t)return f;
        for(auto &i = block[u]; i < sz(G[u]); i++){
            Edge &e = G[u][i];
            if(e.cap <= e.flow)continue;
            int v = e.to;
            if(dis[v] == dis[u] + 1){
                ll cur = dfs(v, min(f, e.cap - e.flow));
                if(cur > 0){
                    e.flow += cur;
                    G[v][e.rev].flow -= cur;
                    return cur;
                }
            }
        }
        return 0;
    }
    ll max_flow(){
        ll ans = 0;
        while(bfs()){
            fill(all(block), 0);
            while(ll _cur = dfs(s, LLONG_MAX))
                ans += _cur;
        }
        return ans;
    }
};
ll solve2(vector<ll> &A, vector<ll> &B, int monkey, int T){
    int nodes = sz(A) + sz(B) + 2, s = 0;
    int t = nodes - 1;
    Dinic Graph(nodes, s, t);
    sort(rall(A));
    sort(all(B));
    for(int i = 0; i < monkey; i++){
        Graph.addEdge(s, i + 1, 1);
        Graph.addEdge(sz(A) + i + 1, t, 1);
    }
    for(int i = 0; i < sz(A); i++){
        for(int j = 0; j < sz(B); j++){
            if(abs(A[i] - B[j]) < T){
                Graph.addEdge(i + 1, sz(A) + j + 1, 1);
                if(i >= monkey){//no puede agregar un nodo donde habia un mono inicialmente
                    Graph.addEdge(sz(A) + j + 1, i + 1, 1);
                }
            }
        }
    }
    return Graph.max_flow();
}
void solve(){    
    int monkey, n, m;
    ll T;
    while(cin >> monkey >> n >> m >> T){
        vector<ll> A(n), B(m);
        for(auto &i : A)cin >> i;
        for(auto &i : B)cin >> i;
        cout << ((solve2(A, B, monkey, T) == monkey || solve2(B, A, monkey, T) == monkey) ? "S" : "N") << '\n';
    }
}
int main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++)
        solve();

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
