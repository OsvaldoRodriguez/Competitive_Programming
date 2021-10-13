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
#define cls(a, car)     memset(a,car,sizeof (a))
#define db(x)           cout << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
void debug(){cout << endl;}
template<typename T, typename... Args>
void debug(T a, Args... args){cout << a << " "; debug(args...);}
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e2 + 15;
const ll mod = 1e9 + 7;
const double E = 1e-7;
string str;
ll v[30][30];
ll dp[N][N][30];
ll f(int i, int k, int last){
    // debug(i, k, last);
    if(k < 0)
        return -1e15;
    if(i == sz(str))
        return 0;
    ll &ans = dp[i][k][last];
    if(ans == -1){
        ans = -1e9;
        for(int j = 0; j < 26; j++){
            ans = max(ans, f(i + 1, k, str[i] - 'a') + v[last][str[i] - 'a']);
            ans = max(ans, f(i + 1, k - 1, j) + v[last][j]);
        }
    }
    return ans;
}
void solve(){   
    int k;
    char a, b;
    int cost;
    cin >> str >> k;
    int q;
    cin >> q;
    while(q--){
        cin >> a >> b >> cost;
        v[a - 'a'][b - 'a'] = cost;
    }   
    cls(dp, -1);
    cout << f(0, k, 29) << '\n'; 

}
int main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
       ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){ 
        solve();
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
