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
int par[N];
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
    memset(vis, -1, sizeof vis);
    vis[0] = 0;
    queue<int> q;
    q.push(0);
    while(q.size()){
        int u = q.front(); q.pop();
        for(int v : G[u]){
            if(vis[v] == -1){
                par[v] = u;
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
    }

    if(vis[n - 1] != -1){
        stack<int> path;
        int node = n - 1;
        cout << vis[n - 1] + 1 << "\n";
        while(node != 0){
            path.push(node);
            node = par[node];
        }
        path.push(0);

        while(path.size()){
            cout << path.top() + 1 << " ";
            path.pop();
        }
    }else
        cout << "IMPOSSIBLE\n";

}

int main(){
    // fastio;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++)
        solve();
    return 0;
}
