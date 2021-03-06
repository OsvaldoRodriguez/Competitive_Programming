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
const int N = 1e6 + 10;
const ll mod = 998244353;
const double E = 1e-7;
const int oo = 1e9;
string str;
ll dp[N][3];
ll f(int i, int sum){
    if(i == sz(str) && sum == 0)
        return 0;
    ll &ans = dp[i][sum];
    if(ans == -1){
        ans = 0;
        if(str[i] >= '0' && str[i] <= '9'){
            int aux = (sum * 10 + (str[i]  - '0')) % 3;
            ans += f(i + 1, aux) + (aux == 0);

        }
    }
    return ans;
}
void solve(){
    while(cin >> str){
        cls(dp, -1);
        ll ans = 0;
        for(int i = 0; i < sz(str); i++){
            if(str[i] >= '0' && str[i] <= '9')
                ans += f(i, 0);
        }
        cout << ans << '\n';
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
        cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
