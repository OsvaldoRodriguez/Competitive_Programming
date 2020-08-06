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
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll n, k;
ll f(ll x){
    return x - (x / n);
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int t;
    cin >> t;
    w(t){
        cin >> n >> k;
        ll a = 0, b = 2e12, mid;
        while(b - a > 1){
            mid = (a + b) >> 1;
            if(f(mid) <= k)
                a = mid;
            else
                b = mid;
        }
        if(a % n == 0)
            a--;
        cout << a << "\n";
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
