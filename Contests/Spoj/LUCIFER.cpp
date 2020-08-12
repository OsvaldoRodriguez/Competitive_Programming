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
#define ff(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b) 
int n;
vi v;
int dp[20][2][100][100];
bool isPrime(int x){
    if(x < 2)
        return 0;
    if(x == 2)return 1;
    if(x % 2 == 0)return 0;
    for(int i = 3; i * i <= x; i += 2)
        if(x % i == 0)return 0;
    return 1;
}
int f(int i, bool flag, int even, int odd){
    if(i == n)
        return isPrime(even - odd);
    int &ans = dp[i][flag][even][odd];
    if(ans != -1)return ans;
    ans = 0;
    fore(j, 0, 10){
        if(flag or j <= v[i]){
            if((n - i - 1) & 1)
                ans += f(i + 1, flag | (j < v[i]), even + j, odd);
            else
                ans += f(i + 1, flag | (j < v[i]), even, odd + j);
        }
    }
    return ans;
}
int get(int y){
    cls(dp, -1);
    v.clear();
    while(y){
        v.pb(y % 10);
        y /= 10;
    }
    reverse(all(v));
    n = sz(v);
    return f(0, 0, 0, 0);
}
int main(){
    //FL;
    fin;
    int t;
    cin >> t;
    w(t){
        int a, b;
        cin >> a >> b;
        cout << get(b) - get(a - 1) << '\n';
    }
    time;
    return 0;
}    
