#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
const int  M = 201;
vector<pair<int, pair<ll, int> > > G[N];
pair<ll, int> dis[N];  
int k, n, m;
int dijkstra(){
    priority_queue< pair<ll, pair<int, int > >, vector<pair<ll, pair<int, int > > >, greater<pair<ll, pair<int, int > > > > pq;
    dis[0] = {0LL, 0};
    pq.push({0LL, {0, 0}});
    while(!pq.empty()){
        ll dist = pq.top().F; 
        int u = pq.top().S.S;
        pq.pop();
        if(dist > dis[u].F)
            continue;
        fore(i, 0, sz(G[u])){
            int v = G[u][i].F;
            ll cost = G[u][i].S.F;
            int tipo = G[u][i].S.S;
            pair<ll, int> can = {cost + dis[u].F, tipo};
            if(can < dis[v]){
                dis[v] = can;
                pq.push({dis[v].F, {tipo, v}});
            }
        }
    }
    int tmp = 0;
    fore(i, 0, n){
        if(dis[i].S == 1)
            tmp++;
    }
    return k - tmp;
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int u, v;
    ll w;
    cin >> n >> m >> k;
    fore(i, 0, n)
        dis[i] = {LONG_LONG_MAX, 1};
    while(m--){
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].pb({v, {w, 0}});
        G[v].pb({u, {w, 0}});
    }
    fore(i, 0, k){
        cin >> u >> w;
        u--;
        G[0].pb({u, {w, 1}});
    }
    cout << dijkstra() << '\n';
    return 0;
}   
