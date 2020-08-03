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
vector<tuple<int, int, int>> G; // (w, u, v)
int P[N], rnk[N];
int n, m;
/*
n vetex
m edges
Complexity
Time:
    kruskal -> O(m log n)
*/
int FIND(int u){return u == P[u] ? u : FIND(P[u]);}
void init(){
    for(int i = 0; i < n; i++){
        P[i] = i;
        rnk[i] = 0;
    }
}
int kruskal(){
    init(); // disjoint set union
    ll ans = 0;
    sort(all(G));
    for(int i = 0; i < m; i++){
        int w, u, v;
        tie(w, u, v) = G[i];
        int pu = FIND(u);
        int pv = FIND(v);
        if(pu != pv){
            if(rnk[pu] < rnk[pv])
                swap(pu, pv);
            P[pv] = pu;
            if(rnk[pu] == rnk[pv])
                rnk[pu]++;
            ans += w;
        }
    }
    return ans;
}



int main(){
    //FL;
    FIN;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G.pb({w, u, v});
    }
    cout << kruskal() << '\n';
    EjecuteTime;
    return 0;
}       