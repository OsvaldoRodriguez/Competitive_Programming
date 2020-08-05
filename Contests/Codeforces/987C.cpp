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
typedef vector<int> vi;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int v[3005],c[3005];
int dp[3005][5][3005];
int n;
int f(int i,int j,int k){
    //cout << i << " " << j << " " << k << endl;
    if(i == n + 1){
        if(j == 3)
            return 0;
        return 1e9;
    }
    if(dp[i][j][k] != -1)return dp[i][j][k];
    int &ans = dp[i][j][k];
    ans = 1e9;
    if(v[i] > v[k] && j <= 3)
        ans = min(ans,f(i + 1,j + 1,i) + c[i]);
    ans = min(ans,f(i + 1,j,k));
    return ans;

}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    cls(dp, -1);
    scanf("%d",&n);
    fore(i, 1, n + 1)
        scanf("%d", &v[i]);
    fore(i, 1, n + 1)
        scanf("%d", &c[i]);
    int sol = f(1, 0, 0);
    if(sol == 1e9)
        sol = -1;
    printf("%d\n",sol);
    return 0;
}   
