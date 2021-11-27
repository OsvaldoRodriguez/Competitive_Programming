#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
const int N = 1e5 + 50;
vi G[N], Ginv[N], SCC(N, 0), vis(N, -1), Top;
int n;
/*
n vetex
m edges
Complexity
Time:
    kosaraju -> O(n + m)
*/
void dfs1(int u){
    vis[u] = 1;
    for(auto v : Ginv[u])
        if(vis[v] == -1)
            dfs1(v);
    Top.push_back(u);
}

void dfs2(int u, int nscc){
    vis[u] = 1;
    SCC[u] = nscc;
    for(auto v : G[u])
        if(vis[v] == -1)
            dfs2(v, nscc);
}

void kosaraju(){
    vis.assign(N, -1);
    for(int i = 0; i < n; i++)
        if(vis[i] == -1)
            dfs1(i);  
    int nscc = 1;
    reverse(Top.begin(), Top.end());
    vis.assign(N, -1);
    for(auto i : Top){
        if(vis[i] == -1){
            dfs2(i, nscc);
            nscc++;
        }
    } 
}

int main(){
    int m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
        Ginv[v].push_back(u);
    }
    kosaraju();
    return 0;
}
