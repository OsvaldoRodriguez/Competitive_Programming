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
#define cls(a, car)     memset(a,car,sizeof (a))
#define db(x)           cout << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
void debug(){cout << endl;}
template<typename T, typename... Args>
void debug(T a, Args... args){cout << a << " "; debug(args...);}
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e6 + 15;
const ll mod = INT_MAX;
const double E = 1e-7;
int P[N], rnk[N];
void init(int n){
    for(int i = 0; i <= n; i++)
        P[i] = i, rnk[i] = 1;
}
int _find(int u){return u == P[u] ? u : P[u] = _find(P[u]);}
void solve(){
    int n, u, v, w;
    cin >> n;
    string str;
    vector<tuple<int, int, int>> E;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> str;
            string cur = str;
            if(j + 1 < n)
                cur = str.substr(0, sz(str) - 1);
            if(atoi(cur.data()) > 0)
                E.pb({atoi(cur.data()), i, j});
        }
    }

    sort(all(E));
    init(n);
    for(int i = 0; i < sz(E); i++){
        tie(w, u, v) = E[i];
        int node1 = u, node2 = v;
        // debug(w, u, v);
        u = _find(u);
        v = _find(v);
        if(u != v){
            if(rnk[u] > rnk[v]){
                P[v] = u;
            }else{
                P[u] = v;
                if(rnk[u] == rnk[v])
                    rnk[v]++;
            }
            cout << char(node1 + 'A') << "-" << char(node2 + 'A') << " " << w << '\n';
        }
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
    cin >> t;
    for(int i = 1; i <= t; i++){ 
        cout << "Case " << i << ":\n";
        solve();
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
