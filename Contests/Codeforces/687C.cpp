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
int dp[505][505], newdp[505][505];
int n, k;
int a[595];
/*bool f(int i, int lit, int big){
    if(big < 0 or lit < 0)return 0;
    if(i == n)
        return (lit == 0 && big == 0);
    int &ans = dp[i][lit][big];
    if(ans != -1)return ans;
    ans = 0;
    ans |= f(i + 1, lit - a[i], big - a[i]);
    ans |= f(i + 1, lit, big - a[i]);
    ans |= f(i + 1, lit, big);
    return ans;
}
*/
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    cin >> n >> k;
    fore(i, 0, n)
        cin >> a[i];
    //cls(dp, 0);
    for(int i = n; i >= 0; i--){
        fore(lit, 0, k + 1){
            fore(big, 0, k + 1){
                if(i == n)
                    newdp[lit][big] = (lit == 0 && big == 0);
                else{
                    
                    newdp[lit][big] = dp[lit][big];
                    if(big >= a[i]){
                        newdp[lit][big] |= dp[lit][big - a[i]];
                        if(lit >= a[i])
                            newdp[lit][big] |= dp[lit - a[i]][big - a[i]];

                    }
                }
            }
        }
        fore(lit, 0, k + 1)
            fore(big, 0, k + 1)
                dp[lit][big] = newdp[lit][big];
    }
    vi aux;
    fore(i, 0, k + 1)
        if(dp[i][k])
            aux.pb(i);
    cout << sz(aux) << '\n';
    for(auto i : aux)
        cout << i << ' ';
    return 0;
}   
