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
vector<vector<int>> G;
int depth[N];
int _set[N];
int n, m, k;
int vis[N];
void dfs(int u, int p, int col){
    _set[u] = col;
    for(auto v : G[u])
        if(v != p)
            dfs(v, u, 1 - col);
}
stack<int> s;
void dfs1(int u, int p, int pro){
    depth[u] = pro;
    vis[u] = 1;
    s.push(u);
    int back = -1;
    for(auto v : G[u]){
        if(vis[v] == -1){
            dfs1(v, u, pro + 1);
        }else if(vis[v] == 1 && v != p){
            if(back == -1)
                back = v;   
            else if(depth[back] < depth[v])   
                back = v;      
        }
    }
    if(back != -1){
        vi cur;
        while(sz(s) && s.top() != back){
            cur.pb(s.top());
            s.pop();
        }
        cur.pb(back);
        if(sz(cur) <= k){
            cout << "2\n";
            cout << sz(cur) << '\n';
            for(auto j : cur)cout << j + 1 << ' ';cout << '\n';
        }else{
            cout << 1 << '\n';
            int cnt = 0;
            fore(j, 0, sz(cur)){
                if(!(j & 1)){
                    cnt++;
                    cout << cur[j] + 1 << ' ';
                }
                if(cnt == (k + 1) / 2)break;
            }
            cout << '\n';
        }
        exit(0);
    }
    vis[u] = 2;
    s.pop();

}
void solve(){
    int u, v;
    cin >> n >> m >> k;
    G.assign(n + 1, vector<int>());
    fore(i, 0, m){
        cin >> u >> v;
        u--;
        v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    fore(i, 0, n){
        random_shuffle(G[i].begin(), G[i].end());
    }
    if(n - 1 == m){//set
        dfs(0, -1, 1);
        int cnt = accumulate(_set, _set + n, 0);
        int aux = 0;
        if(cnt >= n - cnt)
            aux = 1;
        cout << 1 << '\n';
        int cur = 0;
        fore(i, 0, n){    
            if(_set[i] == aux){
                cout << i + 1 << ' ';
                cur++;
            }
            if(cur == (k + 1) / 2)break;
        }
        cout << '\n';
    }else{
        cls(vis, -1);
        dfs1(0, 0, 0);
    }
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
