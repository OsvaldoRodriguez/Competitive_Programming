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
#define ff(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e5 + 5;
const ll mod = 998244353;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b) 
vi G[1005]; 
int main(){
    
    //FL;
    fin;
    int n;
    cin >> n;
    int v[n];
    int idx[n + 1];
    cls(idx, 0);
    fore(i, 0, n){
        cin >> v[i];
        G[v[i]].pb(i);
    }
    fore(i, 1, 1e3 + 1){
        //cout << i << " { ";
        fore(j, 0, sz(G[i])){
            //cout << G[i][j] << ' ';
            int l = G[i][j] - 1;
            int r = G[i][j] + 1;
            bool l1 = 0;
            bool r1 = 0;
            if(G[i][j] == 0 or G[i][j] + 1 == n)
                l1 = 1;
            if(l >= 0){
                if(idx[l] == 1)
                    l1 = 1;
            }
            if(r < n){
                if(idx[r] == 1)
                    r1 = 1;
            }
            if(l1 or r1){
                int mn = 1e4;
                fore(i, 0, n)
                    if(idx[i] == 0)
                        mn = min(mn, v[i]);
                cout << mn << '\n';
                return 0;
            }else idx[G[i][j]] = 1;
        }
        //cout << endl;
    }
    time;
    return 0;
}   
