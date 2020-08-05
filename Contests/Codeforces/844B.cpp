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
int v[55][55];
int main(){
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    fin;
    int n, m;
    cin >> n >> m;
    fore(i, 0, n)
        fore(j, 0, m)
            cin >> v[i][j];

    ll ans = 0;
    fore(i, 0, n){
        ll tmp = 0;
        fore(j, 0, m){
            if(v[i][j] & 1)
                tmp++;
        }
        if(tmp)
            ans += (1LL << tmp) - 1;
        if(m - tmp > 0)
            ans += (1LL << (m - tmp)) - 1;
    }

    fore(i, 0, m){
        ll tmp = 0;
        fore(j, 0, n){
            if(v[j][i] & 1)
                tmp++;
        }
        if(tmp)
            ans += (1LL << tmp) - 1;
        if(n - tmp > 0)
            ans += (1LL << (n - tmp)) - 1;
    }
    cout << ans - m * n << '\n';
    return 0;
}   
