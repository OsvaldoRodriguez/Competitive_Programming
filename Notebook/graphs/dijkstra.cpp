#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
#define F           first
#define S           second
#define pb          push_back
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a)   for(int i = a; i >= 0; i--)
#define fori(i,m)   for(auto i = m.begin(); i != m.end(); i++) 
#define w(t)        while(t--)
#define sz(s)       int(s.size())
#define cls(a,car)  memset(a,car,sizeof (a))
#define db(x)       cerr << #x << " is " << x << '\n'
#define FL          freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
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
        int u = q.top().S;
        int d = q.top().F;
        q.pop();
        if(d > dis[u])continue;
        fore(i, 0, sz(G[u])){
            int v = G[u][i].F;
            int cost = G[u][i].S;
            if(dis[u] + cost < dis[v]){
                dis[v] = dis[u] + cost;
                path[v] = u;
                q.push({dis[v], v});
            }
        }
    }
}

int main(){
    //FL;
    FIN;
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        ll c;
        cin >> u >> v >> c;
        u--;
        v--;
        G[u].pb({v, c});
        G[v].pb({u, c});
    }
    dijkstra(0);
    EjecuteTime;
    return 0;
}       
