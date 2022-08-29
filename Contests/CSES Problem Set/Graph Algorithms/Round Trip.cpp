// calcular todos los ciclos
#include "bits/stdc++.h"
#include "algorithm"
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
int parent[N]; // para reconstruir ciclo
vector<int> color[N]; // a que color pertenece cada nodo
vector<int> cycles[N];
int nro_ciclos; // cuantos ciclos ya hay
void dfs(int u, int p){

    // si ya encontre un ciclo, ya no busco mas
    if(cycles[1].size())
        return;
    // cout << u + 1 << endl;
    for(int v : G[u]){
        if(v == p)
            continue;
        if(vis[v] == -1){
            vis[v] = 1;
            parent[v] = u;
            dfs(v, u);
            vis[v] = 2;
        }else if(vis[v] == 1){
            nro_ciclos++;
            // color[v].push_back(nro_ciclos);
            cycles[nro_ciclos].push_back(v);
            int node = u;
            while(node != v){
                // color[node].push_back(nro_ciclos);
                cycles[nro_ciclos].push_back(node);
                node = parent[node];
            }
        }
    }
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

    for(int i = 0; i < n; i++)
        random_shuffle (G[i].begin(), G[i].end());
    memset(vis, -1, sizeof vis);
    for(int i = 0; i < n; i++)
        if(vis[i] == -1)
            dfs(i, i);


    if(nro_ciclos == 0){
        cout << "IMPOSSIBLE\n";
        return;
    } 
    cout << cycles[1].size() + 1 << "\n";
    for(int i = 1; i <= 1; i++){
        for(int j : cycles[i])
            cout << j + 1 << " ";
        // cout << endl;
    }
    cout << cycles[1][0] + 1 << "\n";

    

   
}

int main(){
    // fastio;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++)
        solve();
    return 0;
}
