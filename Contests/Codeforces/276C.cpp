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
#define FL          freopen("in", "r", stdin),freopen("out", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int v[N];
ll arr[N];
int fre[N];
vii query, nw;
int main(){
    //FL;
    FIN;  
    int n, q;
    cin >> n >> q;
    fore(i, 1, n + 1)cin >> v[i];
    w(q){
        int l, r;
        cin >> l >> r;
        fre[l]++;
        fre[r + 1]--;
        query.pb({l, r});
    }
    sort(v + 1, v + n + 1);
    reverse(v + 1, v + n + 1);
    fore(i, 2, n + 1)
        fre[i] += fre[i - 1];
    fore(i, 1, n + 1){
        nw.pb({fre[i], i});
    }
    sort(all(nw));
    reverse(all(nw));
    fore(i, 0, sz(nw)){
        arr[nw[i].S] = v[i + 1]; 
    }
    arr[0] = 0;
    fore(i, 2, n + 1)
        arr[i] += 0ll + arr[i - 1];
    
    ll ans = 0;
    for(auto i : query){
        ans += 0ll + (arr[i.S] - arr[i.F - 1]);
    }
    cout << ans << '\n';
    EjecuteTime;
    return 0;
}       
