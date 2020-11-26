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
const int N = 50;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;
ll v[N];
void solve(){
    int n;
    ll T;
    cin >> n >> T;
    for(int i = 0; i < n; i++)cin >> v[i];
    vector<ll> L;
    int N1 = n / 2 + 1;
    int N2 = n - N1;   
    for(int mask = 0; mask < 1 << N1; mask++){
        ll sum = 0;
        for(int i = 0; i < N1; i++){
            if(mask & (1 << i))
                sum += v[i];
        }
        L.pb(sum);
    }
    sort(all(L));

    ll ans = 0;
    for(int mask = 0; mask < 1 << N2; mask++){
        ll sum = 0;
        for(int i = 0; i < N2; i++){
            if(mask & (1 << i))
                sum += v[i + N1];
        }
        if(sum > T)continue;
        int a = 0, b = sz(L), mid;
        while(b - a > 1){
            mid = (a + b) >> 1;
            if(L[mid] <= T - sum)
                a = mid;
            else
                b = mid;
        }
        ans = max(ans, sum + L[a]);
    }
    cout << ans << '\n';
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
        cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
