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
int n;
vi D1, D2;
int  dp[11][11][11][2][2][2];
int dp1[11][11][11][2][2][2];
int lids;
int f(int i, int last, int len, bool fM, bool fm, bool zero){
    if(i == sz(D1))
        return len;
    int &ans = dp[i][last][len][fM][fm][zero];
    if(ans == -1){
        ans = 0;
        for(int j = 0; j < 10; j++){
            if((fM or j <= D2[i]) and (fm or j >= D1[i])){
                ans = max(ans, f(i + 1, last, len, fM or j < D2[i], fm or j > D1[i], zero or j != 0));
                if(zero or j != 0){
                    if(j > last - 1)
                        ans = max(ans, f(i + 1, j + 1, len + 1, fM or j < D2[i], fm or j > D1[i], zero or j != 0));
                }
            }
        }
    }
    return ans;
}

int ways(int i, int last, int len, bool fM, bool fm, bool zero){
    if(i == sz(D1))
        return (len == lids ? 1 : 0);
    int &ans = dp1[i][last][len][fM][fm][zero];
    if(ans == -1){
        ans = 0;
        for(int j = 0; j < 10; j++){
            if((fM or j <= D2[i]) and (fm or j >= D1[i])){
                ans += ways(i + 1, last, len, fM or j < D2[i], fm or j > D1[i], zero or j != 0);
                if(zero or (j != 0)){
                    if(j + 1 > last)
                        ans += ways(i + 1, j + 1, len + 1, fM or j < D2[i], fm or j > D1[i], zero or j != 0);
                }
            }
        }
    }
    return ans;

}
void get(int x, vector<int> &v){
    v.clear();
    while(x){
        v.pb(x % 10);
        x /= 10;
    }
    reverse(all(v));
}
void solve(){
    int x, y;
    cin >> x >> y;
    get(x, D1);
    get(y, D2);
    reverse(all(D1));
    while(sz(D1) < sz(D2))
        D1.pb(0);
    reverse(all(D1));   

    cls(dp, -1);
    cls(dp1, -1);
    lids = f(0, 0, 0, 0, 0, 0);
    cout << lids << " " << ways(0, 0, 0, 0, 0, 0) << '\n';
    
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
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
