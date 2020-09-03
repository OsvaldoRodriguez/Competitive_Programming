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
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
string str;
ll nb, ns, nc, pb, ps, pc;
ll b, s, c;
ll r;
bool f(ll x){
    ll cost = 0;
    ll auxb = 0, auxs = 0, auxc = 0;
    auxb = max(0LL, b * x - nb);
    cost += auxb * pb;
    auxs = max(0LL, s * x - ns);
    cost += auxs * ps;
    auxc = max(0LL, c * x - nc);
    cost += auxc * pc;

    return cost <= r;
}
void solve(){
    cin >> str;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;
    for(int i = 0; i < sz(str); i++){
        b += (str[i] == 'B');
        s += (str[i] == 'S');
        c += (str[i] == 'C');
    }
    ll l = 0, r = 2e12, mid;
    while(r - l > 1){
        mid = (l + r) >> 1;
        if(f(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
}
int main(){
    FIN;
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    EjecuteTime;
    return 0;
}       
