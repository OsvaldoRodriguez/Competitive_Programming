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
#define FI          freopen("input.txt", "r", stdin)
#define FO          freopen("output.txt", "w", stdout)
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e5 + 5;
const ll mod = 998244353;
const double E = 1e-7;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
vector<pair<int, ll>> G[N];
int police[N], boster[N];
ll dis_thief[N], dis_police[N];
int n, m, p, x, a, b;
void dijkstra(int type){
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> q;//dis, node, type
    if(type == 0){
        q.push({0, a, 0});
        dis_thief[a] = 0;
    }else{
        fore(i, 0, n){
            if(police[i]){
                q.push({0, i, boster[i]});
                dis_police[i] = 0;
            }
        }
    }
    while(sz(q)){
        int u, t; ll d;
        tie(d, u, t) = q.top();
        q.pop();
        if(!type){
            if(dis_thief[u] < d)continue;
        }else{
            if(dis_police[u] < d)continue;
        }
        
        fore(i, 0, sz(G[u])){
            int v = G[u][i].F;
            ll cost = G[u][i].S;
            
            if(!type){
                if(dis_thief[u] + cost < dis_thief[v]){
                    dis_thief[v] = cost + dis_thief[u];
                    q.push({dis_thief[v], v, 0});
                }
            }else{
                if(t){
                    if(2LL * dis_police[u] + cost < 2LL * dis_police[v]){
                        dis_police[v] = dis_police[u] + cost / 2;
                        q.push({dis_police[v], v, t});
                    }
                }else{
                    if(dis_police[u] + cost < dis_police[v]){
                        dis_police[v] = cost + dis_police[u];
                        q.push({dis_police[v], v, t or boster[v]});
                    }
                }
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    fore(i, 0, n + 1){
        dis_thief[i] = dis_police[i] = 1e18;
    }
    fore(i, 0, m){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }
    cin >> p;
    fore(i, 0, p){
        cin >> x;
        police[x] = 1;
    }
    cin >> p;
    fore(i, 0, p){
        cin >> x;
        boster[x] = 1;
    }
    cin >> a >> b;
    dijkstra(0);
    dijkstra(1);
    if(dis_police[b] <= dis_thief[b])
        cout << -1 << '\n';
    else
        cout << dis_thief[b] <<  '\n';
}   
int main(){
    FIN;
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    EjecuteTime;
    return 0;
}  
