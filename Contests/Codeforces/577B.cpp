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
const ll mod = 1000000;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int v[N * 10];
int n, m;
int dp[1010][1010];
int f(int i, int j){
    if(i == n)
        return 0;
    if((v[i] + j) % m == 0)return 1;
    int &ans = dp[i][j];
    if(ans != -1)return ans;
    ans = 0;
    ans |= f(i + 1, (j % m + v[i] % m) % m);
    ans |= f(i + 1, j);
    return ans;
}
int main(){
    fin;
    cls(dp, -1);
    cin >> n >> m;
    fore(i, 0, n){
        cin >> v[i];
    }
    if(n > m)cout << "YES\n";
    else
        cout << (f(0, 0) ? "YES" : "NO") << '\n';
    return 0;
}   
