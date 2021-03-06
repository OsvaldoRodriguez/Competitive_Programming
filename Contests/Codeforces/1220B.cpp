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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll v[1005][1005];
ll ans[1005];
bool check(int n){
    fore(i, 0, n){
        fore(j, 0, n){
            if(i == j)
                continue;
            if(ans[i] * ans[j] != v[i][j])return 0;
        }
    }
    return 1;
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int n;
    cin >> n;
    fore(i, 0, n)fore(j, 0, n)cin >> v[i][j];
    ll gcd = v[0][1];
    fore(i, 1, n)
        gcd = __gcd(gcd, v[0][i]);
    for(int i = 1; i * i <= gcd; i++){
        if(gcd % i == 0){
            for(int j = 0; j < n; j++)
                ans[j] = v[0][j] / i;
            ans[0] = i;
            if(check(n)){
                fore(j, 0, n)
                    cout << ans[j] << ' ';
                return 0;
            }
                fore(j, 0, n)
                    ans[j] = v[0][j] / (gcd / i);
                ans[0] = (gcd / i);
                if(check(n)){
                    fore(j, 0, n)
                        cout << ans[j] << ' ';
                    return 0;
                }
            
        }
    }
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
