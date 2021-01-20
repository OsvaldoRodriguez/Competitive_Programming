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
#define db(x)           cout << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
void debug(){cout << endl;}
template<typename T, typename... Args>
void debug(T a, Args... args){cout << a << " "; debug(args...);}
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 5e2 + 10;
const ll mod = 1e9 + 7;
const double E = 1e-7;
vii G[N];
vi fire; 
vi dis, _dis;
void dijkstra(vector<int> &D){
    priority_queue<ii> q;
    
    for(auto i : fire){
        D[i] = 0;
        q.push({0, i});
    }

    while(sz(q)){
        int u = q.top().S;
        int d = q.top().F;
        q.pop();
        if(D[u] < d)continue;
        for(int i = 0; i < sz(G[u]); i++){
            int v = G[u][i].F;
            int cost = G[u][i].S;
            if(D[u] + cost < D[v]){
                D[v] = D[u] + cost;
                q.push({D[v], v});
            }
        }
    }
}
void solve(){
    int f, m, x, u, v, w;
    cin >> f >> m;
    string str;
    fire.clear();
    while(f--){
        cin >> x;
        fire.pb(--x);
    }
    cin.ignore();
    dis.assign(m, 1e9);
    for(int i = 0; i <= m; i++)
        G[i].clear();
    
    while(getline(cin, str)){
        if(str == "")break;
        vi aux;
        for(int i = 0; i < sz(str); i++){
            string _cur = "";
            while(i < sz(str) and str[i] != ' ')
                _cur += str[i++];
            aux.pb(atoi(_cur.data()));
        }

        G[aux[0] - 1].pb({aux[1] - 1, aux[2]});
        G[aux[1] - 1].pb({aux[0] - 1, aux[2]});
    }
    dijkstra(dis);

    int node = -1;
    int mn = 1e9;
    for(int i = 0; i < m; i++){
        fire.pb(i);
        _dis = dis;
        dijkstra(_dis);
        fire.pop_back();
        int cur = 0;
        for(int j = 0; j < m; j++)
            cur = max(cur, _dis[j]);
        if(mn > cur){
            node = i;
            mn = cur;
        }
    }
    cout << node + 1 << '\n';
}
int main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
       ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        if(i > 1)
            cout << '\n';
        solve();
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
