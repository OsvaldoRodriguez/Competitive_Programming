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
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    string str;
    vi v;
    for(int k = 1; k <= t; k++){
        v.clear();
        while(getline(cin, str)){
            if(str == "")
                break;
            v.pb(atoi(str.data()));

        }
        vi dp(sz(v), 1);
        for(int i = 1; i < sz(v); i++){
            for(int j = 0; j < i; j++)
                if(v[j] < v[i])
                    dp[i] = max(dp[i], dp[j] + 1);
        }
        int id = max_element(all(dp)) - dp.begin();
        if(k > 1)cout << '\n';
        cout << "Max hits: " << dp[id] << '\n';
        vi ans(1, v[id]);
        for(int i = id - 1; i >= 0; i--){
            if(v[i] < v[id] && dp[i] == dp[id] - 1){
                ans.pb(v[i]);
                id = i;
            }
        }
        reverse(all(ans));
        for(auto i : ans)cout << i << '\n';

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
    for(int i = 1; i <= t; i++){
        solve();
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
