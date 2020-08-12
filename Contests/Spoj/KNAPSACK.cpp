#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
#define w(t) while(t--)
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
// LIS 
int dp[2002][2002];
int c[2002], g[2002];
int W, n;
int f(int  i, int j){
    if(j < 0)return -1e9;
    if(i == n)
        return 0;
    int &ans = dp[i][j];
    if(ans != -1)return ans;
    ans = -1e9;
    ans = max(ans, f(i + 1, j));
    ans = max(ans, f(i + 1, j - c[i]) + g[i]);
    return ans;
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    cin >> W >> n;
    cls(dp, -1);
    fore(i, 0, n)
        cin >> c[i] >> g[i];
    cout << f(0, W) << '\n';
    return 0;
}    
