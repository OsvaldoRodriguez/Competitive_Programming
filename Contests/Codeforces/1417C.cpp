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
void solve(){
    int n;
    cin >> n;
    map<int, vi> m;
    fore(i, 0, n){
        int x;
        cin >> x;
        if(!m.count(x))
            m[x].pb(-1);
        m[x].pb(i);
    }
    for(auto i : m)
        m[i.F].pb(n);
    vi ans(n + 1, 1e7);
    for(auto i : m){
        int cur = 0;
        fore(j, 1, sz(i.S))
            cur = max(cur, i.S[j] - i.S[j - 1]);
        
            ans[cur] = min(ans[cur], i.F);
        
    }
    int i = 1;
    int cur =  1e9;
    while(i < sz(ans) && ans[i] == 1e7)i++;
    for(; i < sz(ans); i++){
        cur = min(cur, ans[i]);
        ans[i] = min(ans[i], cur);
    }
    fore(i, 1, sz(ans)){
        ans[i] = (ans[i] == 1e7 ? -1 : ans[i]);
        cout << ans[i] << " ";
    }
    cout << '\n';
}   

int main(){
    FIN;
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    EjecuteTime;
    return 0;
}  
