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
const int N = 1e3 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;
vi G[N];
int vis[N];
struct punto{
    int x, y;
    punto(): x(0), y(0) {};
    punto(int x, int y): x(x), y(y) {};
};

struct node{
    int d, nod, a, b;
    node(): d(0), a(0), b(0), nod(0) {};
    node(int d, int a, int b, int nod): d(d), a(a), b(b), nod(nod) {};
};

bool cmp(node &a, node &b){
    if(a.d == b.d){    
        if(a.a == b.a){    
            if(a.b == b.b)
                return a.b < b.b;
            return a.nod < b.nod;
        }
        return a.a < b.a;    
    }
    return a.d < b.d;
}
int s(int x){return x * x;}
int d(punto &a, punto &b){
    return s(a.x - b.x) + s(a.y - b.y);
}

void dfs(int u){
    vis[u] = 1;
    for(int v : G[u])
        if(vis[v] == -1)
            dfs(v);
}
void solve(){
    int n;
    while(cin >> n && n){
        vector<punto> v(n + 1);
        for(int i = 0; i < n; i++){
            G[i].clear();
            cin >> v[i].x >> v[i].y;
        }
        
        for(int i = 0; i < n; i++){
            int mn = 1e9;
            vector<node> aux;
            for(int j = 0; j < n; j++){
                if(i == j)continue;
                aux.pb({d(v[i], v[j]), abs(v[i].x - v[j].x), abs(v[i].y - v[j].y), j});
            }
            int cnt = 0;
            sort(all(aux), cmp);
            for(int j = 0; j < min(sz(aux), 2); j++)
                G[i].pb(aux[j].nod);
        }
        cls(vis, -1);
        dfs(0);
        bool flag = 1;
        for(int i = 0; i < n; i++)
            if(vis[i] == -1)
                flag = 0;
        cout << (flag ? "All stations are reachable." : "There are stations that are unreachable.") << '\n';
    }
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
