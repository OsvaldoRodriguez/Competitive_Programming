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
int n;
int v[105];
int dp[105][5];
// 0 descansar
// 1 contest
// 2 ejercicio
int f(int i,int last){
    if(i == n)
        return 0;
    if(dp[i][last] != -1)return dp[i][last];

    int &ans = dp[i][last] = 1e9;
    if(v[i] == 0)
        ans = min(ans, f(i + 1, 0) + 1);
    if(v[i] == 1){
        if(last != 1)
            ans = min(ans, f(i + 1, 1));
        else
            ans = min(ans, f(i + 1, 0) + 1);
    }
    if(v[i] == 2){
        if(last != 2)
            ans = min(ans,f(i + 1, 2));
        else
            ans = min(ans,f(i + 1,0) + 1);
    }
    if(v[i] == 3){
        if(last != 1)
            ans = min(ans,f(i + 1, 1));
        else ans = min(ans,f(i + 1, 0) + 1);
        if(last != 2)
            ans = min(ans,f(i + 1, 2));
        else ans = min(ans,f(i + 1, 0) + 1);
        
    }
    return ans;
}
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    fast;
    //cls(dp, -1);
    cin >> n;
    fore(i, 0, n)cin >> v[i];
    fore(i, 0, n)
        fore(j, 0, 3)
            dp[i][j] = 1e9;

    dp[n][0] = 0;
    for(int i = n - 1; i >= 0; i--){
        fore(j,0,3){
            if(v[i] == 0)
                dp[i][j] = min(dp[i][j],dp[i + 1][0] + 1);
            if(v[i] == 1){
                if(j != 1)
                    dp[i][j] = min(dp[i][j],dp[i + 1][1]);
                else
                    dp[i][j] = min(dp[i][j],dp[i + 1][0] + 1);
            }
            if(v[i] == 2){
                if(j != 2)
                    dp[i][j] = min(dp[i][j],dp[i + 1][2]);
                else
                    dp[i][j] = min(dp[i][j],dp[i + 1][0] + 1);
            }
            if(v[i] == 3){
                if(j != 1)
                    dp[i][j] = min(dp[i][j],dp[i + 1][1]);
                else
                    dp[i][j] = min(dp[i][j],dp[i + 1][0] + 1);

                if(j != 2)
                    dp[i][j] = min(dp[i][j],dp[i + 1][2]);
                else
                    dp[i][j] = min(dp[i][j],dp[i + 1][0] + 1);
            }
        }
    }
    cout << dp[0][0] << '\n';
    return 0;   
}
