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
const int N = 2e2 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int n;
string s, t;
int dp[N][N][N];
int f(int i, int cnt, int k){
    //cout << i << " " << cnt << " " << k << endl;
    if(k < 0)
        return -1e9;
    if(i == sz(s))
        return 0;
    int &ans = dp[i][cnt][k];
    if(ans == -1){
        ans = 0;
        if(t[0] != t[1]){
            if(s[i] != t[0] && s[i] != t[1]){
                ans = max(ans, f(i + 1, cnt + 1, k - 1));
                ans = max(ans, f(i + 1, cnt, k - 1) + cnt);
            }else{
                if(s[i] == t[0]){
                    ans = max(ans, f(i + 1, cnt + 1, k));
                    ans = max(ans, f(i + 1, cnt, k - 1) + cnt);
                }
                if(s[i] == t[1]){
                    ans = max(ans, f(i + 1, cnt, k) + cnt);
                    ans = max(ans, f(i + 1, cnt + 1, k - 1));
                }
            }
        }else{
            if(s[i] != t[0] && s[i] != t[1]){
                ans = max(ans, f(i + 1, cnt + 1, k - 1));
                ans = max(ans, f(i + 1, cnt + 1, k - 1) + cnt);
            }else{
                if(s[i] == t[0]){
                    ans = max(ans, f(i + 1, cnt + 1, k) + cnt);
                }
                if(s[i] == t[1]){
                    ans = max(ans, f(i + 1, cnt + 1, k) + cnt);
                }
            }
        }
        ans = max(ans, f(i + 1, cnt, k));
    }
    return ans;
}
void solve(){
    int k;
    cin >> n >> k;
    cin >> s >> t;
    cls(dp, -1);
    cout << f(0, 0, k) << '\n';
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
