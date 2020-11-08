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
#define db(x)           cerr << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;
vector<int> z_function(string &s){
    int n = sz(s);
    vector<int> z(n);
    z[0] = 0;
    for(int i = 1, l = 0, r = 0; i < n; i++){
        if(i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < n && s[z[i]] == s[z[i] + i])
            z[i]++;
        if(i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
void solve(){
    int k;
    string t, p;
    cin >> t >> p >> k;
    string s = p + "#" + t;
    vi z = z_function(s);
    reverse(all(t));
    reverse(all(p));
    s = p + "#" + t;
    vi x = z_function(s);

    vi ans;
    for(int i = sz(p) + 1; i < sz(z) - sz(p) + 1; i++){
        int aux = sz(z) - i + 1;
        if(z[i] + x[aux] + k >= sz(p))
            ans.pb(i - sz(p));
    }   
    cout << sz(ans) << '\n';
    for(int i = 0; i < sz(ans); i++){
        cout << ans[i];
        if(i + 1 != sz(ans))cout << ' ';
    }
    if(sz(ans))
        cout << '\n';
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
