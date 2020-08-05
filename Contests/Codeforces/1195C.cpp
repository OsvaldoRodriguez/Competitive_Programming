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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
int a[N], b[N], n;
ll dp[N][2];
ll f(int i,int last){
    if(i == n + 1)
        return 0;
    if(dp[i][last] != -1)return dp[i][last];
    ll &ans = dp[i][last];
    if(last == 0){
        ans = max(ans,f(i + 1, last));
        ans = max(ans, f(i + 1, 1) + b[i]);
    }
    if(last == 1){
        ans = max(ans, f(i + 1, last));
        ans = max(ans, f(i + 1, 0) + a[i]);
    }
    return ans;
} 
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    cin >> n;
    cls(dp, -1);
    fore(i, 1, n + 1)
        cin >> a[i];
    fore(i, 1, n + 1)
        cin >> b[i];
    cout << f(0, 0) << '\n';
    return 0;
}   
