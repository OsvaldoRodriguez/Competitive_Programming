#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<long long,long long>
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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int A[4];
int dp[4005];
int coin(int u){
    if(u == 0)
        return 0;
    if(dp[u] != -1)
        return dp[u];
    dp[u] = -(1 << 30);
    for(int i = 0; i < 3; i++){
        if(u >= A[i])
            dp[u] = max(dp[u], 1 + coin(u - A[i]));
    }
    return dp[u];
}
int main(){
    int n;
    cin >> n >> A[0] >> A[1] >> A[2];
    cls(dp,-1);
    cout << coin(n) << '\n';
    return 0;
}
    