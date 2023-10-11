#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define fastio      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll          long long
#define all(_)      (_).begin(), (_).end()
#define sz(_)       int(_.size())
#define pii         pair<int, int>
#define pll         pair<ll, ll>
using namespace std;
// using namespace __gnu_pbds; // ordered_set
const int N = 2e5 + 5;
ll mod = 998244353;
const double eps = 1e-9;
// less<type>  prioridad menor
// greater<type>  prioridad mayor
// add equal<type>  less_equal or greater_equal // multiset
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int di[] = {1, 0, 0, -1}, dj[] = {0, -1, 1, 0};
// string dir = "DLRU";
//**********************************************************************
// Later or Sooner discipline overcomes talent, come on, I can do it.
// ll A[N], H[N];
 
 
// Min cut: nodes with dist>=0 vs nodes with dist<0
// Matching MVC: left nodes with dist<0 + right nodes with dist>0
struct Dinic{
    struct Edge{
        // rev is the index in the graph G ie.
        // if a edge is (to, rev, cap, flow) then, if the edge is of the graph then rev is the 
        // index of edge in the residual graph
        // if si the edge is of the residual graph then rev is the index of edge in the graph
        int to, rev;
        ll cap, flow;
        Edge(int to, int rev, ll cap, ll flow): to(to), rev(rev), cap(cap), flow(flow){}
    };
    vector<vector<Edge>> G;
    vector<int> dis, block;
    int n, s, t;    
    Dinic(){}
    Dinic(int n, int s, int t): n(n), dis(n), block(n), s(s), t(t), G(n){}
    void addEdge(int u, int v, ll cap){
        // rev -> is the index in the graph where is the edge of residual graph
        // or viceversa
        // that's why the first edge add is G[v].size(), because v's length is the index where it'll 
        // be 
        // that's why the second edge add is G[u].size() - 1, because u's length - 1 is
        // the index where it've been to add.
        G[u].push_back((Edge){v, (int) G[v].size(), cap, 0});
        G[v].push_back((Edge){u, (int) G[u].size() - 1, 0, 0});
    }
    bool bfs(){
        fill(dis.begin(), dis.end(), -1);
        dis[s] = 0;
        queue<int> q; q.push(s);
        while(q.size()){
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
        for(auto &i = block[u]; i < (int) G[u].size(); i++){
            Edge &e = G[u][i];
            if(e.cap <= e.flow) continue;
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
            fill(block.begin(), block.end(), 0);
            while(ll _cur = dfs(s, LLONG_MAX))
                ans += _cur;
            
        }
        return ans;
    }
 
    vector<pii> min_cut_edges(){
        bfs();
        vector<pii> edges;
        for(int i = 0; i < G.size(); i++){
            for(auto &e : G[i]){
                if(e.flow == e.cap and e.cap > 0 and dis[i] != -1 and dis[e.to] == -1){
                    edges.push_back({i, e.to});
                }
            }
        }
        return edges;
    }
 
    void mostrar(){
        cout << "\ngraph\n";
        for(int i = 0; i < G.size(); i++){
            if(G[i].size()){
                cout << i << " -> ";
                for(auto j : G[i]){
                    cout << "(" << j.to  << " " << j.rev  << " " << j.cap << " " << j.flow << ")";
                }
                cout << "\n";
            }
        }
        cout << endl;
    }
};
 
void solve(){
 
 
    int n, m, k;
    cin >> n >> m >> k;
    Dinic flow = Dinic(n + m + 2, 0, n + m + 1);
 
    map<int, int> to;
    map<int, int> prev;
 
    for(int i = 1; i <= m; i++){
        to[i] = n + i;
        prev[n + i] = i;
    }
    // between pairs create a edge with capacity 1, because is potential pair also 
    // we need prove all pairs
    for(int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;
        v = to[v];
        flow.addEdge(u, v, 1);
        // flow.addEdge(v, u, 1);
    }
 
    // since s we add edge a all boys with capacity 1
    for(int i = 1; i <= n; i++){
        flow.addEdge(0, i, 1);
        // flow.addEdge(i, 0, 1);
    }
 
    // since all girls to s add edge with capacity 1
    for(int i = 1; i <= m; i++){
        flow.addEdge(to[i], n + m + 1, 1);
        // flow.addEdge(n + m + 1, to[i], 1);
    }
 
    cout << flow.max_flow() << "\n";
    // flow.mostrar();
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < flow.G[i].size(); j++){
            if(flow.G[i][j].cap and flow.G[i][j].flow == 1){
                cout << i << " " << prev[flow.G[i][j].to] << "\n";
            }
        }
    }
 
    
}
int main(){
    fastio;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}   
// solo recorre en los bits encendidos
// O(bits_encendidos en mask)
// for(int x = mask; x; x &= (x - 1)){
//     int v = __builtin_ctz(x); // da la posicion donde esta 
// }    
