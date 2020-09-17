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
    Top.pb(u);
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
    reverse(all(Top));
    vis.assign(N, -1);
    for(auto i : Top){
        if(vis[i] == -1){
            dfs2(i, nscc);
            nscc++;
        }
    } 
}

int main(){
    //FL;
    FIN;
    int m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        u--;v--;
        G[u].pb(v);
        Ginv[v].pb(u);
    }
    kosaraju();
    EjecuteTime;
    return 0;
}       
