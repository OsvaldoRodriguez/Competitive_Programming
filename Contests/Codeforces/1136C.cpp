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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b) 
vi G1[1010], G2[1010];
int main(){
    //FL;
    fin;
    int n, m;
    cin >> n >> m;
    fore(i, 0, n){
        fore(j, 0, m){
            int x;
            cin >> x;
            G1[i + j].pb(x);
        }
    }


    fore(i, 0, n){
        fore(j, 0, m){
            int x;
            cin >> x;
            G2[i + j].pb(x);
        }
    }
    fore(i, 0, n + m){
        sort(all(G2[i]));
        sort(all(G1[i]));
        fore(j, 0, sz(G2[i]))
            if(G2[i][j] != G1[i][j]){
                cout << "NO\n";
                return 0;
            }
    }
    cout << "YES\n";
    time;
    return 0;
}   
