#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;
const double E = 1e-9;
vector<pair<int, ll>> G[N];  // (u, (v, w))
vector<ll> dis(N, 1e18);
vi path(N);
/*
n vetex
m edges
Complexity
Time:
    dijkstra -> O(m * log (n))
*/
priority_queue< pair<ll, int> , vector< pair<ll, int> >, greater<pair<ll, int>>> q;
void dijkstra(int node){
    q.push({0LL, node}); // (dis, node)
    dis[node] = 0;
    while(!q.empty()){
        int u = q.top().second;
        int d = q.top().first;
        q.pop();
        if(d > dis[u])continue;
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i].first;
            int cost = G[u][i].second;
            if(dis[u] + cost < dis[v]){
                dis[v] = dis[u] + cost;
                path[v] = u;
                q.push({dis[v], v});
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        ll c;
        cin >> u >> v >> c;
        u--;
        v--;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    dijkstra(0);
    return 0;
}       
