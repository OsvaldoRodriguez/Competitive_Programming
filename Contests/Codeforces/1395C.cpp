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
//int _dx[] = {0, 1}, _dy[] = {1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int A[N], B[N];
int dp[2][520];
int n, m;
int f(int i, int val){
    int &ans = dp[i][val];
    if(i == n)
        return ans = val;
    if(ans == -1){
        ans = 1e9;
        for(int j = 0; j < m; j++)
            ans = min(ans, f(i + 1, val | (A[i] & B[j])));
    }
    return ans;
}
int main(){
    FIN;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int j = 0; j < m; j++){
        cin >> B[j];
    }
    for(int i = n; i >= 0; i--){
        for(int val = 0; val < (1 << 9); val++){
            int &ans = dp[i & 1][val];
            if(i == n){
                ans = val;
                continue;
            }
            ans = 1e9;
            for(int j = 0; j < m; j++)
                ans = min(ans, dp[(i + 1) & 1][val | (A[i] & B[j])]);
        }
    }
    cout << dp[0][0] << '\n';
    EjecuteTime;
    return 0;
}       
