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
int main(){
    fin;
    int t;
    cin >> t;
    w(t){
        ll ans = 0;
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if(x == y && x == 0)
            cout << 0 << '\n';
        else{
            ll aux1 = 0;
            ll aux2 = 0;
            if(x < y){
                ans += x * b;
                ans += (y - x) * a;
            }else{
                ans += y * b;
                ans += (x - y) * a;
            }
            aux1 += a * x + a * y;
            ans = min(ans, aux1);
            cout << ans << '\n';
        }
    }
    return 0;
}   
