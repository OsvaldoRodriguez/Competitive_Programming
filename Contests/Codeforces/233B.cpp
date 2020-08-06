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
ll n;
ll f(ll x){
    ll ans = 0;
    while(x){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
ll fx(ll x){return x * x + f(x) * x - n;}
int main(){
    
    //FL;
    fin;
    cin >> n;
    ll ans = -1;
    for(ll i = 1; i <= 1e6; i++){
        ll dis = sqrt(i * i + 4LL * n);
        if(dis * dis == i * i + 4LL * n){
            ll x = (dis + i) >> 1;
            if(2 * x == (dis + i) && fx(x) == 0){
                ans = x;
            }
            x = (dis - i) >> 1;
            if(2 * x == (dis - i) && fx(x) == 0){
                ans = x;
            }

        }
    }
    cout << ans << '\n';
    time;
    return 0;
}   
