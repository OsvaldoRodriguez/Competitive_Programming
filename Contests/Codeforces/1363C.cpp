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
#define db(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x) double(x * acos(-1) / 180.0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
vi G[1010], vis(1010, -1);
int cnt = 0;
void dfs(int u){
    vis[u] = 1;
    cnt++;
    for(auto v : G[u])
        if(vis[v] == -1)
            dfs(v);
}
int main(){
    //FL;
    fin;
    int t;
    cin >> t;
    w(t){

        cnt = 0;
        int n, node;
        cin >> n >> node;
        fore(i, 0, n)
            G[i].clear();
        vis.assign(1010, -1);
        --n;
        w(n){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            G[u].pb(v);
            G[v].pb(u);
        }
        --node;
        if(sz(G[node]) <= 1)
            cout << "Ayush\n";
        else{
            dfs(node);
            if(cnt & 1)
                cout << "Ashish\n";
            else
                cout << "Ayush\n";
        }
    }
    time;
    return 0;
}       
