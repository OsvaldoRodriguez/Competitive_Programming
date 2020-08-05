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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll dp[20][10][2];
int n;
string str;
ll f(int i, int dig, int flag){
    if(dig > 3)return 0;
    if(i == n)
        return dig <= 3;
    ll &ans = dp[i][dig][flag];
    if(ans != -1)return ans;
    ans = 0;
    fore(j, 0, 10){
        if(flag or j <= str[i] - '0'){
            int dg = j != 0;
            int sw = j < str[i] - '0';
            ans += f(i + 1, dig + dg, flag | sw);
        }
    }
    return ans;
}
int main(){
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    fin;
    int t;
    cin >> t;
    w(t){
        ll x, y;
        cin >> x >> y;
        --x;
        str = to_string(x);
        n = sz(str);
        cls(dp, -1);
        int l = f(0, 0, 0);
        str = to_string(y);
        cls(dp, -1);
        n = sz(str);
        int r = f(0, 0, 0);
        cout << r - l << '\n';

    }
    return 0;
}   
