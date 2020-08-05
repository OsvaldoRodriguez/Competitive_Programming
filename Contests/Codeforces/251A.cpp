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
const int  M = 201;
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int n, d;
    cin >> n >> d;
    ll ans = 0;
    int v[n + 1];
    fore(i, 0, n) cin >> v[i];
    fore(i, 0, n - 2){
        int a = i - 1, b = n, mid;
        while(b - a > 1){
            mid = (a + b) >> 1;
            if(v[mid] - v[i] <= d)
                a = mid;
            else
                b = mid;
        }
        ll df = a - i;
            if(df > 1){
                ans += df * (df - 1LL) / 2LL;
            }
    }
    cout << ans << '\n';
    return 0;
}   
