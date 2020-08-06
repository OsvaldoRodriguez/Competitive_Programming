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
#define db(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x) double(x * acos(-1) / 180.0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e6 + 500;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll dp[2002][2][2002];
int n, d, m;
vi v;
ll f(int i, bool flag, int sum){
    if(i == n)return sum % m == 0;
    ll &ans = dp[i][flag][sum];
    if(ans != -1)return ans;
    ans = 0;
    fore(j, 0, 10){
        if(flag or j <= v[i]){
            if(i & 1 && j != d)continue;
            if(!(i & 1) && j == d)continue;
            ans = (ans % mod + f(i + 1, flag | (j < v[i]), (sum * 10 + j) % m) % mod) % mod;
        }
    }
    return ans;
}
ll get(const string &a){
    v.assign(sz(a), 0);
    cls(dp, -1);
    fore(i, 0, sz(a))
        v[i] = a[i] - '0';
    
    n = sz(a);
    return f(0, 0, 0);
}
int main(){
    //FL;
    fin;
    cin >> m >> d;
    string a, b;
    cin >> a >> b;
    string aa = "";
    forr(i, sz(a) - 1){
        if(a[i] == '0')
            a[i] = '9';
        else{
            a[i]--;
            break;
        }
    }
    cout << (get(b) - get(a) + mod) % mod << '\n';
    time;
    return 0;
}       
