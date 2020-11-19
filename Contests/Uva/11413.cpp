#include <bits/stdc++.h>
#define ii              pair<int,int>
#define F               first
#define S               second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define rall(x)         (x).rbegin(),(x).rend()
#define fore(i, a, b)   for(int i = a; i < b; i += 1)
#define forr(i, a)      for(int i = a; i >= 0; i--)
#define sz(s)           int(s.size())
#define cls(a,car)      memset(a,car,sizeof (a))
#define db(x)           cout << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
void debug(){cout << endl;}
template<typename T, typename... Args>
void debug(T a, Args... args){cout << a << " "; debug(args...);}
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e3 + 10;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;
ll n, m;
ll v[N];
bool f(ll x){
    ll cur = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(cur + v[i] <= x)
            cur += v[i];
        else{
            ans++;
            cur = v[i];
        }
    }
    if(cur > 0)
        ans++;
    return ans <= m;
}
void solve(){
    while(cin >> n >> m){
        for(int i = 0; i < n; i++)cin >> v[i];
        if(m >= n){
            cout << *max_element(v, v + n) << '\n';
            continue;
        }
        ll a = *max_element(v, v + n) - 1, b = 1e18, mid;
        while(b - a > 1){
            mid = (a + b) >> 1;
            if(f(mid)){
                b = mid;
            }
            else
                a = mid;
        }
        cout << b << '\n';
    }
}
int main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
       ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++)
        solve();

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
