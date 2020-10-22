#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
#define F           first
#define S           second
#define pb          push_back
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a)   for(int i = a; i >= 0; i--)
#define fori(i,m)   for(auto i = m.begin(); i != m.end(); i++) 
#define w(t)        while(t--)
#define sz(s)       int(s.size())
#define cls(a,car)  memset(a,car,sizeof (a))
#define db(x)       cerr << #x << " is " << x << '\n'
#define FI          freopen("input.txt", "r", stdin)
#define FO          freopen("output.txt", "w", stdout)
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e2 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int INF = 1e2;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
//105470163083
//100000000223257 primos
//1000000000318157
ll dp[65][65][905];
int n;
ll k;
ll f(int i, int count, int inv){
    ll &ans = dp[i][count][inv];
    if(i == n)return ans = (inv == k);
    if(ans == -1){
        ans = 0;
        ans += f(i + 1, count, inv + count);
        ans += f(i + 1, count + 1, inv);
    }
    return ans;
}

void r(int i, int count, int inv, ll k){
    if(i == n)
        return;
    if(k <= dp[i + 1][count][inv + count]){
        cout << "A";
        r(i + 1, count, inv + count, k);
        return;
    }
    if(dp[i + 1][count][inv + count] > 0)
        k -= dp[i + 1][count][inv + count];
    
    if(k <= dp[i + 1][count + 1][inv]){
        cout << "B";
        r(i + 1, count + 1, inv, k);
        return;
    }
}

void solve(){
    cin >> n >> k;
    cls(dp, -1);
    ll ans = f(0, 0, 0);
    if(ans & 1){
        r(0, 0, 0, (ans + 1) / 2);
        cout << '\n';
    }
    else{
        r(0, 0, 0, ans / 2);
        cout << '\n';
        r(0, 0, 0, ans / 2 + 1);
        cout << '\n';
    }
}
int main(){
    FIN;
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    EjecuteTime;
    return 0;

}