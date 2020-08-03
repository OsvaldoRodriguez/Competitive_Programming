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
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int n;
    cin >> n;
    int v[n + 1];
    int even = 0;
    int odd = 0;
    fore(i, 0, n){
        cin >> v[i];
        if(v[i] & 1)
            odd++;
        else
            even++;
    }
    sort(v, v + n);
    reverse(v, v + n);
    int pr;
    if(abs(odd - even) == 1){
        cout << 0 << '\n';
        return 0;

    }
    if(odd > even){
        int df = even;
        odd = df + 1;
        even = df;
    }
    else{
        int df = odd;
        even = df + 1;
        odd = df;
    }   
    fore(i, 0, n){
        if(v[i] & 1 && odd > 0){
            v[i] = -1;
            odd--;
        }
        if(!(v[i] & 1) && even > 0){
            v[i] = -1;
            even--;
        }
    }
    ll ans = 0;
    fore(i, 0, n){
        if(v[i] != -1)
            ans += v[i];
    }
    cout << ans << '\n';
    return 0;
}   