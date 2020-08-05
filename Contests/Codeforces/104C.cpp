#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
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
const int N = 3 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
vi G[105], vis(105, -1);
void dfs(int u){
    vis[u] = 1;
    for(int v : G[u])
        if(vis[v] == -1)
            dfs(v);
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fast;
    int n, m, u, v;
    cin >> n >> m;
    fore(i, 0, m){
        cin >> u >> v;
        u--;v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    int d = 0;
    fore(i, 0, n){
        if(vis[i] == -1){
            d++;
            dfs(i);
        }
    }
    cout << (d == 1 && n == m? "FHTAGN!": "NO") << '\n';
    return 0;
}   
