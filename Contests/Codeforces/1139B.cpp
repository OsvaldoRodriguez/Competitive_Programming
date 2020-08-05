#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
//freopen("","r",stdin);
//freopen("","w",stdout);
int main(){
    fast;
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &i : v)cin >> i;
    ll ans = v[n - 1];
    ll ant = v[n - 1];
    for(int i = n - 2; i >= 0; i--){
        ll aux = min(v[i],ant);
        if(aux == ant && aux > 0)
            aux--;
        ans += aux;
        ant = aux;
    }
    cout << ans << '\n';
	return 0;
}
