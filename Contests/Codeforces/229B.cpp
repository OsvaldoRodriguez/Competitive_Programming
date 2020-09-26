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
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
vector<pair<int, ll>> G[N];
ll dis[N];
vector<ll> T[N], TT[N];
int n, m;
bool BS(int i, int L, int R, ll val){
    if(L == R)
        return 0;
    int a = L, b = R;
    while(b - a > 1){
        int mid = (a + b) >> 1;
        if(T[i][mid] <= val)
            a = mid;
        else
            b = mid;
    }
    return T[i][a] == val;
}

ll BS1(int i, int L, int R, ll val){
    int a = L, b = R;
    while(b - a > 1){
        int mid = (a + b) >> 1;
        if(TT[i][mid] >= val)
            b = mid;
        else
            a = mid;
    }
    return TT[i][b];
}
void dijkstra(int node = 0){
    int dd = 0;
    int _cur = 0;
    for(int i = 0; i < sz(T[0]); i++){
        if(T[0][i] == _cur)
            _cur++;
        else
            break;
    }
    dis[node] = _cur;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, node});
    while(sz(q)){
        int u = q.top().S;
        ll d = q.top().F;
        q.pop();
        if(dis[u] < d)continue;
        fore(i, 0, sz(G[u])){
            int v = G[u][i].F;
            ll cost = G[u][i].S;
            bool cur = BS(u, 0, sz(T[u]), dis[u]);
            if(!cur){
                if(dis[u] + cost < dis[v]){
                    dis[v] = dis[u] + cost;
                    q.push({dis[v], v});
                }
            }else{
                ll aux = BS1(u, -1, sz(TT[u]) - 1, dis[u]) - dis[u];
                if(dis[u] + cost + aux < dis[v]){
                    dis[v] = dis[u] + cost + aux;
                    q.push({dis[v], v});
                }
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;v--;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }
    for(int i = 0; i < n; i++){
        dis[i] = 1e18;
        int len;
        cin >> len;
        fore(j, 0, len){
            int x;
            cin >> x;
            T[i].pb(x);
        }
        fore(j, 1, len){
            if(T[i][j] - 1 != T[i][j - 1]){
                TT[i].pb(T[i][j - 1] + 1);
            }
            if(j + 1 == len)
                TT[i].pb(T[i][j] + 1);
        }
        if(len == 1)
            TT[i].pb(T[i][0] + 1);
    }
    
    dijkstra();
    ll ans = dis[n - 1];
    if(ans == 1e18)
        ans = -1;
    cout << ans << '\n';
    
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
