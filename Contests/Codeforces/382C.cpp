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
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll v[N];
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> v[i];
    sort(v,v + n);
    if(n == 1){
        cout << -1 << '\n';
        return ;
    }
    map<ll, int> m;
    set<ll> s;
    for(int i = 1; i < n; i++)
        m[v[i] - v[i - 1]]++;
    if(sz(m) >= 3){
        cout << 0 << '\n';
        return ;
    }
    auto it = m.begin();
    ll cur = (*it).F;
    it++;
    if(sz(m) == 1){
        s.insert(v[0] - cur);
        s.insert(v[n - 1] + cur);
        if(n == 2 && (v[1] - v[0]) % 2 == 0)
            s.insert(v[0] + cur / 2);
    }else{
        if((*it).S > 1 or (*(--it)).F == 0){
            cout << 0 << '\n';
            return ;
        }
        for(int i = 0; i < n - 1; i++)
            if(v[i] + cur + cur == v[i + 1])
                s.insert(v[i] + cur);
    }
    cout << sz(s) << '\n';
    for(int i : s)
        cout << i << ' ';cout << '\n';
}
int main(){
    FIN;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    EjecuteTime;
    return 0;
}       
