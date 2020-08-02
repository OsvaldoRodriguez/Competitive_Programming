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
#define FL          freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 3e5 + 50;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int _dx[] = {0, 1}, _dy[] = {1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll dp[N][3][3], v[N];
int n;
ll x;
ll f(int i, int flag, int aug){
    if(i == n)return 0;
    ll &ans = dp[i][flag][aug];
    if(ans == -1){
        ans = 0;
        if(flag == 0){ 
            ans = max(ans, f(i + 1, 0, 0));
            ans = max(ans, f(i + 1, 1, 0) + v[i]);
            ans = max(ans, f(i + 1, 1, 1) + v[i] * x);
            
        }else if(flag == 1){ // flag 1
            if(aug == 0){
                ans = max(ans, f(i + 1, 1, 0) + v[i]);
                ans = max(ans, f(i + 1, 1, 1) + v[i] * x);
                ans = max(ans, f(i + 1, 2, aug));
            }
            if(aug == 1){
                ans = max(ans, f(i + 1, 1, 1) + v[i] * x);
                ans = max(ans, f(i + 1, 1, 2) + v[i]);
                ans = max(ans, f(i + 1, 2, 2));
            }
            if(aug == 2){
                ans = max(ans, f(i + 1, 1, 2) + v[i]);
                ans = max(ans, f(i + 1, 2, 2));
            }
        }else{
            ans = max(ans, f(i + 1, 2, aug));
        }
    }
    return ans;
}
int main(){
    //FL;
    FIN;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cls(dp, -1);
    cout << f(0, 0, 0) << '\n';
    EjecuteTime;
    return 0;
}       