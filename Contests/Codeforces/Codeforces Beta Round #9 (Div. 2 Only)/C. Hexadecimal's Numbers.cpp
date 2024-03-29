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
typedef unsigned long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e2 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int dp[12][2];
vi v;
int f(int i, bool flag){
    if(i == sz(v))
        return 1;
    int &ans = dp[i][flag];
    if(ans == -1){
        ans = 0;
        for(int j = 0; j < 2; j++){
            if(flag or j <= v[i]){
                // todos los numeros que sean validos
                ans += f(i + 1, flag or j < v[i]); 
            }
        }
    }
    return ans;
}

int get(int n){
    v.clear();
    while(n > 0){
        v.pb(n % 10);
        n /= 10;
    }
    reverse(all(v));
    cls(dp, -1);
    return f(0, 0);
}
void solve(){
    int n;
    cin >> n;
    cout << get(n) - get(0) << '\n';

}
int main(){
    FIN;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    EjecuteTime;
    return 0;
}       
