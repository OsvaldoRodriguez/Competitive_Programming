#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
vector<int> G[N];
int vis[N];
void dfs(int u){
    vis[u] = 1;
    for(int v : G[u])
        if(vis[v] == -1)
            dfs(v);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, m, l;
        cin >> n >> m >> l;
        for(int i = 0; i <= n; i++)
            G[i].clear();
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            G[u].push_back(v);
        }
        for(int i = 0; i < n; i++)
            vis[i] = -1;
        int cnt = 0;
        while(l--){
            int node;
            cin >> node;
            node--;
            dfs(node);

        }
        for(int i = 0; i < n; i++)
            cnt += (vis[i] == 1 ? 1 : 0);

        cout << cnt << '\n';
    }
    return 0;
}
