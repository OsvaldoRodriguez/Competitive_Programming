#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;

/*
Complexity O(V^2 * E)
donde:
V: vertices
E: aristas
*/

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
void solve(){
    int n;
    int test = 1;
    while(cin >> n && n){
        int s, t, c;
        int u, v; ll cap;
        cin >> s >> t >> c;
        Dinic D(n, s - 1, t - 1);
        for(int i = 0; i < c; i++){
            cin >> u >> v >> cap;
            u--;v--;
            D.addEdge(u, v, cap);
            D.addEdge(v, u, cap);
        }
        cout << "Network " << test++ << '\n';
        cout << "The bandwidth is ";
        cout << D.max_flow() << ".\n";
        cout << '\n';
    }
}
int main(){
    solve();
    return 0;
}  
