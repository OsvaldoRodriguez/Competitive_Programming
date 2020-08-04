#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define cls(s) s.clear()
#define sz(s) int(s.size())
#define	mst(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll INF = LONG_LONG_MAX;
ll f(ll x){return x * (x + 1) >> 1;}
vector<ll> v;
int main(){
	fast;
	ll n;
	for(ll i = 1; i < 10; i++){
		n = 0;
		for(ll j = 0; j < 10; j++){
		 	n = n * 10 + i;
			v.pb(n);
		}
	}
	sort(all(v));
	int t;
	ll x;
	cin >> t;
	while(t--){
		int a = -1 , b = sz(v), m;
		cin >> x;
		while(b - a > 1){
			m = (a + b) >> 1;
			if(v[m] <= x)
				a = m;
			else
				b = m;
		}
		cout << a + 1<< '\n';
	}
	return 0;
}
