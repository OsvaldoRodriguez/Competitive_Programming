#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
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
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int a[105],b[105];
int dp[105][200010];
int n,k;
int mid = 100000;
int f(int i,int c){
    if(i == n){
        if(c == mid)
            return 0;
        return -1e9;
    }
    if(dp[i][c] != -1)return dp[i][c];
    dp[i][c] = -1e9;
    return dp[i][c] = max(f(i + 1,c),f(i + 1,c + a[i] - k * b[i]) + a[i]);
 
}
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    //cls(dp, -1);
    fast;
    cin >> n >> k;     
    fore(i,0,n)cin >> a[i];
    fore(i,0,n)cin >> b[i];
    fore(i, 0, n + 1)
        fore(j, 0, 2 * N)
            dp[i][j] = -1e9;
    dp[n][mid] = 0;
    for(int i = n - 1; i >= 0; i--){
        fore(j, 0, 200010){
            dp[i][j] = max(dp[i + 1][j],dp[i + 1][j + a[i] - k * b[i]] + a[i]);
        }
    }
    int sol = dp[0][mid];
    if(sol <= 0)
        cout << "-1\n";
    else
        cout << sol << '\n';
    return 0;   
}
