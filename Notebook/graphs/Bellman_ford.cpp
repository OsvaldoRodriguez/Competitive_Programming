#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
const int N = 1e3 + 5;
int n, m;
int dis[N];
vector<tuple<int, int, int>> G;

/*
n -> vertex
m -> edges
Complexity
Time:
    bellman ->  O((n - 1) * m)
    
Space:
    O(m)
*/
void bellman(){
    dis[0] = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < G.size(); j++){
            int u, v, w;
            tie(u, v, w) = G[j];
            dis[v] = min(dis[v], dis[u] + w);
        }
    }
}
void solve(){
    cin >> n >> m;
    G.clear();
    for(int i = 0; i < n; i++){
        dis[i] = 1e9;
    }
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        G.push_back({u, v, w});
    }
    bellman();
}  
int main(){
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}  
