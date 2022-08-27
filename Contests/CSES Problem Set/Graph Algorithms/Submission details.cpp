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
    bool flag = true;
    for(int  k = 0; k < n; k++){
        if(vis[k] != -1)
            continue;
        vis[k] = 0;
        queue<int> q;
        q.push(k);
        while(q.size()){
            int u = q.front(); q.pop();
            for(int v : G[u]){
                if(vis[v] == -1){
                    vis[v] = vis[u] ^ 1;
                    q.push(v);
                }else if(vis[v] == vis[u])
                    flag = false;
            }
        }
    }

    if(flag){
        for(int i = 0; i < n; i++)
            cout << vis[i] + 1 << " ";
    }else
        cout << "IMPOSSIBLE\n";

}

int main(){
    fastio;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++)
        solve();
    return 0;
}
