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
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 3 * 1e5 + 5;
const ll mod = 1e6 + 3;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll dp[N][3][4];
int n;
string s;
ll f(int i, int est, int sum){
    if(i == n)
        return est > 0 && sum == 0;//)return 1;
    if(est == 2 && sum == 0)return 1;
    ll &ans = dp[i][est][sum];
    if(ans != -1)return ans;
    ans = 0;
    int val = (sum * 10 + (s[i] - '0')) % 4;
    if(est == 0){
        ans += f(i + 1, 1, val);
        ans += f(i + 1, 0, sum);
    }
    if(est == 1){
        ans += f(i + 1, 1, val);
        ans += f(i + 1, 2, sum);
    }
    return ans;
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    cls(dp, -1);
    cin >> s;
    n = sz(s);
    cout << f(0, 0, 0) << '\n';
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
