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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll v[N];
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int t, n;
    cin >> t;
    ll ans = 0;
    w(t){
        ans = 0;
        cin >> n;
        fore(i, 0, n)  cin >> v[i];
        int i = 0;
        bool flag;
        if(v[0] > 0)
            flag = 1;
        else
            flag = 0;
        while(i < n){
            if(flag){
                int j = i + 1;
                ll mx = v[i];
                while(j < n && v[j] > 0){
                    mx = max(mx, v[j++]);
                }
                i = j;
                ans += mx;
                flag = 0;
            }else{
                flag = 1;
                int j = i + 1;
                ll mn = v[i];
                while(j < n && v[j] < 0){
                    mn = max(mn, v[j++]);
                }
                i = j;
                flag = 1;
                ans += mn;
            }
        }
        cout << ans << "\n";

    }
    return 0;
}   
