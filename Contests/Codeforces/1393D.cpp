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
const int N = 2e3 + 5;
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
string v[N];
int n, m;
int dp[N][N];
int f(int i, int j){
    if(i == 0 or j == 0 or j + 1 == m)
        return 1;
    int &ans = dp[i][j];
    if(ans == -1){
        ans = 1;
        char cur = v[i][j];
        if(cur == v[i - 1][j] && cur == v[i - 1][j - 1] && cur == v[i - 1][j + 1]){
            ans = min({f(i - 1, j), f(i - 1, j - 1), f(i - 1, j + 1)});
            if(i >= 2 * ans && cur == v[i - 2 * ans][j])
                ans++;
        }
    }
    return ans;
}
int main(){
    FIN;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dp[i][j] = 1;
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m - 1; j++){
            char cur = v[i][j];
            int &ans = dp[i][j];
            if(cur == v[i - 1][j - 1] && cur == v[i - 1][j] && cur == v[i - 1][j + 1]){
                ans = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]});
                if(i >= 2 * ans && cur == v[i - 2 * ans][j])
                    ans++;
            }
        }
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ans += dp[i][j];
    cout << ans << '\n';
    EjecuteTime;
    return 0;
}       
