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
const int N = 4e2 + 5;
ll mod = 998244353;
const ll inf = 1000000000000000000LL;
const double eps = 1e-9;
// less<type>  prioridad menor
// greater<type>  prioridad mayor
// add equal<type>  less_equal or greater_equal // multiset
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int di[] = {1, 0, 0, -1}, dj[] = {0, -1, 1, 0};
string dir = "DLRU";
//**********************************************************************
// Later or Sooner discipline overcomes talent, come on, I can do it.


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
    ll max_flow(){
        ll ans = 0;
        while(bfs()){
            fill(block.begin(), block.end(), 0);
            while(ll _cur = dfs(s, LLONG_MAX))
                ans += _cur;
            
        }
        return ans;
    }

    void mostrar(){
        cout << "\ngraph\n";
        for(int i = 0; i < G.size(); i++){
            if(G[i].size()){
                cout << i << " -> ";
                for(auto j : G[i]){
                    cout << "(" << j.to << " " << j.rev << " " << j.cap << " " << j.flow << ")";
                }
                cout << "\n";
            }
        }
        cout << endl;
    }
};

int A[N][N];
void solve(){
    int n, m;
    cin >> n >> m;
    int nodes = 0;
    int total = n * m * 2 + 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    int sink = x * m + y + 1;
    Dinic flow = Dinic(total, 0, n * m + sink);
    //create graph undirected
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == 0 or flow.t == i * m + j + 1)
                continue;
            // we need to add outvertex source with oo
            if(i == 0 or j == 0 or i == n - 1 or j == m - 1){ // is a borde of board
                // cerr << "ADD 0 to " << i * m + j + 1 << "\n"; 
                flow.addEdge(0, i * m + j + 1, inf);
            
            }
            // edges with capacity
            flow.addEdge(i * m + j + 1, i * m + j + 1 + n * m, A[i][j]);
            
            for(int k = 0; k < 4; k++){
                int ni = i + di[k];
                int nj = j + dj[k];
                if(ni >= 0 and ni < n and nj >= 0 and nj < m and A[ni][nj]){
                    // how the node is divide in two (i, j) (i stay here)
                    // we should connect bb with aa the other node (ni, nj)
                    int u = i * m + j + 1 + (n * m);
                    int v = ni * m + nj + 1; 
                    // edges to conect nodes
                    // it add at the sink and others nodes
                    // the adge is undirected but how you prove both nodes (then it's the same)
                    // becarefully with sink(t) what's why continue when it want to prove it
                    flow.addEdge(u, v, inf);
                }
            }
        }
    }


    cout << flow.max_flow() << "\n";

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
