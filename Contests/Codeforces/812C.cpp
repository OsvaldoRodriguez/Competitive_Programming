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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int v[N], k;
ll arr[N];
ll ans = 0;
int n;
ll f(ll x){
    fore(i, 0, n)
        arr[i] = v[i] + (i + 1) * x;
    sort(arr, arr + n);
    ans = 0;
    fore(i, 0, x)
        ans += arr[i];
    return ans;
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    cin >> n >> k;
    fore(i, 0, n)
        cin >> v[i];
    ll a = -1, b = n + 1, mid;
    while(b - a > 1){
        mid = (a + b) >> 1;
        //cout << mid << '\n';
        if(f(mid) <= k)
            a = mid;
        else
            b = mid;
    }
    cout << a << " " << f(a) << '\n';
    return 0;
}   
