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
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int n;
//1 friend
//0 me
int dp[2][2][4];
int v[N];
int f(int i, bool player, int cnt){
    if(i == n)return 0;
    int &ans = dp[i][player][cnt];
    if(ans == -1){
        ans = 1e9;
        if(player){
            if(cnt < 2){
                if(v[i] == 1)
                    ans = min(ans, f(i + 1, player, cnt + 1) + 1);
                else
                    ans = min(ans, f(i + 1, player, cnt + 1));
            }
            ans = min(ans, f(i + 1, !player, 1) + (v[i] == 1));
        }else{
            if(cnt < 2)
                ans = min(ans, f(i + 1, player, cnt + 1));
            ans = min(ans, f(i + 1, !player, 1));
        }
    }
    return ans;
}
void solve(){
    cin >> n;
    fore(i, 0, n)cin >> v[i];
    fore(i, 0, 2)
        fore(j, 0, 2)
            fore(k, 0, 4)
                dp[i][j][k] = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 4; k++){
                int &ans = dp[i & 1][j][k];
                ans = 1e9;
                if(j){
                    if(k < 2){
                        if(v[i] == 1)
                            ans = min(ans, dp[(i + 1) & 1][j][k + 1] + 1);
                        else
                            ans = min(ans, dp[(i + 1) & 1][j][k + 1]);
                    }
                    ans = min(ans, dp[(i + 1) & 1][!j][1] + (v[i] == 1));
                }else{
                    if(k < 2)
                        ans = min(ans, dp[(i + 1) & 1][j][k + 1]);
                    ans = min(ans, dp[(i + 1) & 1][!j][1]);
                }
            }
    }
    cout << dp[0][1][0] << '\n';
}  
int main(){
    FIN;
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(); 
    }
    EjecuteTime;
    return 0;
}  
