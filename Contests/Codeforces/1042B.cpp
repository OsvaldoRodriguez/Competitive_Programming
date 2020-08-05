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
int A[1005][5];
int dp[1005][16];
int n;
int f(int i, int mask){
    if(i == n){
        if(__builtin_popcount(mask) == 3)
            return 0;
        return 1e9;
    }
    int &ans = dp[i][mask];
    if(ans != -1)return ans;
    ans = 1e9;
    int msk = 0;
    fore(j, 1, 4){
        int p;
        if(A[i][j] == 1){
            p = j - 1;
            msk |= (1 << p);
        }
    }

    ans = min(ans, f(i + 1, mask));
    ans = min(ans, f(i + 1, mask | msk) + A[i][0]);
    return ans;
}
int main(){
    fin;
    cls(dp, -1);
    cin >> n;
    string s;
    fore(i, 0, n){
        cin >> A[i][0] >> s;
        fore(j, 0, sz(s))
        A[i][s[j] - 'A' + 1] = 1;
    }
    int ans = f(0, 0);
    if(ans == 1e9)
        ans = -1;
    cout << ans << '\n';
    return 0;
}   
