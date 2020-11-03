#include <bits/stdc++.h>
#define ii              pair<int,int>
#define F               first
#define S               second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define rall(x)         (x).rbegin(),(x).rend()
#define fore(i, a, b)   for(int i = a; i < b; i += 1)
#define forr(i, a)      for(int i = a; i >= 0; i--)
#define sz(s)           int(s.size())
#define cls(a,car)      memset(a,car,sizeof (a))
#define db(x)           cerr << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;
vi G[10];
int dis[8];
void bfs(int node){
    queue<int> q;
    q.push(node);
    dis[node] = 0;
    while(sz(q)){
        int u = q.front();q.pop();
        for(int v : G[u])
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
    }
}
void solve(){
    int u, v;    
    vi D(6);
    multiset<int> cur;
    for(int i = 0; i < 5; i++){
        cin >> u >> v;
        u--;v--;
        D[u]++;
        D[v]++;
        G[u].pb(v);
        G[v].pb(u);
    }
    for(auto i : D)
        cur.insert(i);

    if(cur == multiset<int>{1, 1, 2, 2, 2, 2})
        cout << 3 << '\n';
    else if(cur == multiset<int>{1, 1, 1, 2, 2, 3}){
        int idx = max_element(all(D)) - D.begin();
        cls(dis, -1);
        bfs(idx);
        int mx = *max_element(dis, dis + 6);
        if(mx == 2)
            cout << 3 << '\n';
        else
            cout << 2 << '\n';
    }else
        cout << 2 << '\n';


}
int main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++)
        solve();

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
