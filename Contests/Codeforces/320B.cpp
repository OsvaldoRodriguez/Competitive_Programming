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
int a[101], b[101];
int i = 1;
int vis[101];
void dfs(int u){
    vis[u] = 1;
    for(int q = 1; q <= i; q++)
        if(vis[q] == -1){
            if(a[u] > a[q] && a[u] < b[q])
                dfs(q);
            if(b[u] > a[q] && b[u] < b[q])
                dfs(q);
        }
}
int main(){
    //FL;
    fin;
    int n;
    cin >> n;
    int ope, x, y;
    w(n){
        cin >> ope >> x >> y;
        if(ope == 1){
            a[i] = x;
            b[i++] = y;
        }else{
            cls(vis, -1);
            dfs(x);
            if(vis[y] == 1)
                cout << "YES";
            else cout << "NO";
            cout << '\n';
        }
    }
    time;
    return 0;
}   
