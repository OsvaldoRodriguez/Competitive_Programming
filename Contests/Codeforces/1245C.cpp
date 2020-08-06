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
#define db(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x) double(x * acos(-1) / 180.0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll dp[N];
string s;
ll ans = 1;
ll f(int i){
    if(i <= 1)
        return 1;
    ll &ans = dp[i];
    if(ans != -1)return ans;
    ans = (f(i - 1) + f(i - 2)) % mod;
    return ans;
}
void solve(const string &a, char cmp){
    ll cur = 0;
    fore(i, 0, sz(a)){
        if(a[i] == cmp)
            cur++;
        else{
            ans = (ans % mod * f(cur)) % mod;
            cur = 0;
        }
    }
    if(cur){
        ans = (ans % mod * f(cur)) % mod;
    }
}
int main(){
    //FL;
    fin;
    cin >> s;
    cls(dp, -1);
    fore(i, 0, sz(s))
        if(s[i] == 'w' or s[i] == 'm'){
            cout << 0 << '\n';
            return 0;
        }
    solve(s, 'n');
    solve(s, 'u');
    cout << ans << '\n';
    EjecuteTime;
    return 0;
}       
