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
const int N = 1e3 + 5;
const ll mod = 1e8 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int x, y, n;
ll dis(int a1, int b1, int a, int b){
    return (a1 - a) * (a1 - a) + (b1 - b) * (b1 - b);
}
ll dp[1 << 25];
ll X[25], Y[25];
ll f(int mask){
    if(__builtin_popcount(mask) == n){
        return 0;
    }
    ll &ans = dp[mask];
    if(ans == -1){
        ans = 1e12;
        for(int i = 0; i < n; i++){
            if(!(mask >> i & 1)){
                ans = min(ans, f(mask ^ (1 << i)) + dis(x, y, X[i], Y[i]) * 2LL);
                for(int j = i + 1; j < n; j++){
                    if(!(mask >> j & 1)){
                        ll cost = dis(X[i], Y[i], X[j], Y[j]);
                        cost += dis(x, y, X[i], Y[i]);
                        cost += dis(X[j], Y[j], x, y);
                        ans = min(ans, f(mask ^ (1 << i) ^ (1 << j)) + cost);
                    }
                }break;
            }
        }
    }
    return ans;
}
vi aux;
void r(int mask){
    if(__builtin_popcount(mask) == n)
        return;

    ll ans = f(mask);
    for(int i = 0; i < n; i++){
        if(!(mask >> i & 1)){
            if(ans == f(mask ^ (1 << i)) + dis(x, y, X[i], Y[i]) * 2LL){
                aux.pb(i + 1);
                aux.pb(0);
                r(mask ^ (1 << i));
                break;
                return;
            }
            for(int j = i + 1; j < n; j++){
                if(!(mask >> j & 1)){
                    ll cost = dis(X[i], Y[i], X[j], Y[j]);
                    cost += dis(x, y, X[i], Y[i]);
                    cost += dis(X[j], Y[j], x, y);
                    if(ans == f(mask ^ (1 << i) ^ (1 << j)) + cost){
                        aux.pb(i + 1);
                        aux.pb(j + 1);
                        aux.pb(0);
                        r(mask ^ (1 << i) ^ (1 << j));
                        break;
                        return ;
                    }
                }
            }break;
        }
    }
}
void solve(){
    cin >> x >> y;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> X[i] >> Y[i];
    cls(dp, -1);
    ll ans = f(0);
    cout << ans << '\n';
    aux.pb(0);
    r(0);
    for(auto i : aux)cout << i << ' ';
    cout << "\n";
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
