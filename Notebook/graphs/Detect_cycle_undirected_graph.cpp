#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
const int N = 1e5 + 50;
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
    for(int i = 0; i < (int) G[u].size(); i++){
        int v = G[u][i];
        if(vis[v] == -1){
            parent[v] = u;
            dfs(v);
        }else if(parent[u] != v)
            ok = 1;
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(vis, -1, sizeof vis);
    ok = 0;
    for(int i = 0; i < n; i++)
        if(vis[i] == -1)
            dfs(i);
    cout << (ok ? "cycle" : "not cycle") << '\n';
    return 0;
}       
