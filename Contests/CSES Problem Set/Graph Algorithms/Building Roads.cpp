#include "bits/stdc++.h"
#define fastio      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll          long long
#define all(_)      (_).begin(), (_).end()
#define sz(_)       int(_.size())
#define pii         pair<int, int>
using namespace std;
const int N = 2e5 + 20;
const int mod = 1e9 + 7;
const double eps = 1e-9;
// DLRU
int di[] = {1, 0, 0, -1}, dj[] = {0, -1, 1, 0};
string dir = "DLRU";
vector<int> G[N];
int vis[N];
int node_color[N];

void dfs(int u, int col){
    vis[u] = 1;
    node_color[col] = u;
    for(int v : G[u])
        if(vis[v] == -1)
            dfs(v, col);
}
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0, u, v; i < m; i++){
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int color = 1;
    memset(vis, -1, sizeof vis);
    for(int i = 0; i < n; i++){
        if(vis[i] == -1){
            dfs(i, color);
            color++;
        }
    }


    // for(int i = 1; i < color; i++)
    //     cout << i << " " << node_color[i] + 1 << endl;

    cout << color - 2 << "\n";
    for(int i = 2; i < color; i++)
        cout << node_color[1] + 1 << " " << node_color[i] + 1 << "\n";


}

int main(){
    // fastio;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++)
        solve();
    return 0;
}
