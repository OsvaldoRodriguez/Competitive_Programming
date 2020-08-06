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
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 998244353;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll POW(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1)
            ans = (ans % mod * a % mod) % mod;
        b >>= 1;
        a = (a % mod * a % mod) % mod;
    }
    return ans;
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int a1 = a * d;
    int b1 = c * b;
    int GCD = __gcd(a1, b1);
    if(a1 < b1)
        swap(a1, b1);
    int tmp_1 = a1 - b1;
    int tmp_2 = max(a1, b1);
    tmp_1 /= GCD;
    tmp_2 /= GCD;
    cout << tmp_1 << '/' << tmp_2 << '\n';
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
