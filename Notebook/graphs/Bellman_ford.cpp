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
const int N = 1e3 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
int n, m;
int dis[N];
vector<tuple<int, int, int>> G;

/*
n -> vertex
m -> edges
Complexity
Time:
    O((n - 1) * m)
    
Space:
    O(m)
*/
void bellman(){
    dis[0] = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < sz(G); j++){
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
        G.pb({u, v, w});
    }
    bellman();
}  
int main(){
    FIN;
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(); 
    }
    EjecuteTime;
    return 0;
}  
