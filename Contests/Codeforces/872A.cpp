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
#define angle(x) double(x * acos(-1) / 180.0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e7 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b) 
int main(){
    //FL;
    fin;
    int n, m;
    vi a, b;
    cin >> n >> m;
    int aa[10], bb[10];
    cls(aa, 0);
    cls(bb, 0);
    fore(i, 0, n){
        int x;
        cin >> x;
        a.pb(x);
        aa[x]++;
    }
    fore(i, 0, m){
        int x;
        cin >> x;
        b.pb(x);
        bb[x]++;
    }
    int ans = 1e9;
    fore(i, 1, 10)
        if(aa[i] && bb[i])
            ans = min(ans, i);
    sort(all(a));
    sort(all(b));
        if(a[0] == b[0])
            ans = min(ans, a[0]);
        else
            ans = min(ans, min(a[0] * 10 + b[0], b[0] * 10 + a[0]));
        cout << ans << '\n';
    time;
    return 0;
}   
