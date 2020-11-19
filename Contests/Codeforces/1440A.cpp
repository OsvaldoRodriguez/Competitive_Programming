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
const int N = 2e5 + 10;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;

void solve(){
    int n, c0, c1, h;
    string str;
    cin >> n >> c0 >> c1 >> h >> str;
    ll ans = 0;
    for(auto i : str)
        ans += (i == '1' ? c1 : c0);
    
    string aux = str;
    ll _aux = h;
    if(c0 <= c1){
        for(int i = 0; i < n; i++){
            if(aux[i] == '0')
                continue;
            ll cur = _aux;
            aux[i] = '0';
            for(int j = 0; j < n; j++)
                cur += (aux[j] == '1' ? c1 : c0);
            ans = min(ans, cur);
            _aux += h;
        }
    }else{
        for(int i = 0; i < n; i++){
            if(aux[i] == '1')
                continue;
            ll cur = _aux;
            aux[i] = '1';
            for(int j = 0; j < sz(str); j++)
                cur += (aux[j] == '1' ? c1 : c0);
            ans = min(ans, cur);
            _aux += h;
        }
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
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve();

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
