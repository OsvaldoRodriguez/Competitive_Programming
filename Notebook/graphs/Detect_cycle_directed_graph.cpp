#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
const int N = 1e5 + 50;
bool ok;
int vis[N];
vi G[N];

/*
n vetex
m edges
Complexity
Time:
    dfs -> O(n + m)
*/

// -1 not visited
// 0 processing
// 1  visited (end)
void dfs(int u){
    for(int i = 0; i < (int) G[u].size(); i++){
        int v = G[u][i];
        if(vis[v] == -1){
            vis[v] = 0;
            dfs(v);
            vis[v] = 1;
        }else if(vis[v] == 0)
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
    }
    memset(vis, -1, sizeof vis);
    ok = 0;
    for(int i = 0; i < n; i++)
        if(vis[i] == -1)
            dfs(i);
    cout << (ok ? "cycle" : "not cycle") << '\n';
    return 0;
}       
