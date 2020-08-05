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
#define w(t) while(t--)
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 998244353;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int arr[1005][1005];
vi G[1005];
int diss[1005];
int dist[1005];
void bfs(int n, int *dis){
    queue<int> q;
    q.push(n);
    dis[n] = 0;
    while(sz(q)){
        int u = q.front(); q.pop();
        for(auto v : G[u])
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
    }
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;t--;
    cls(diss, -1);
    w(m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
        arr[u][v] = arr[v][u] = 1;
    }
    bfs(s, diss);
    cls(dist, -1);
    bfs(t, dist);
    int ans = 0;
    int df = diss[t];
    fore(i, 0, n){
        fore(j, i + 1, n){
            if(arr[i][j])continue;
            int d;
            if(dist[i] > dist[j])
                d = dist[j] + diss[i] + 1;
            else
                d = dist[i] + diss[j] + 1;
            if(d >= df)
                ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}   
