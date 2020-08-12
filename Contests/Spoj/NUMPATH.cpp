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
const int N = 1 * 1e4 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int R, C;
short dp[2][8];
short f(int x, int y){
    if(x < 0 or x >= R or y < 0 or y >= C)return 0;
    if(x == R - 1 && y == C - 1)
        return 1;
    short &ans = dp[x][y];
    if(ans == -1){
        ans = 0;
        for(int i = 0; i < 2; i++){
            ans += f(x + dx[i], y + dy[i]);
        }
    }
    return ans;
}
int main(){
    //FL;
    FIN;
    int t;
    cin >> t;
    while(t--){
        cin >> R >> C;
        cls(dp, 0);
        for(int x = R - 1; x >= 0; x--){
            for(int y = C - 1; y >= 0; y--){
                short &ans = dp[x & 1][y];
                if(x == R - 1 && y == C - 1){
                    ans = 1;
                    continue;
                }
                ans = 0;
                for(int i = 0; i < 2; i++){
                    int u = x + dx[i];
                    int v = y + dy[i];
                    if(u >= 0 && u < R && v >= 0 && v < C)
                        ans += dp[u & 1][v];
                }
 
            }
        }
        cout << dp[0][0] << '\n';
    }
    EjecuteTime;
    return 0;
}    
