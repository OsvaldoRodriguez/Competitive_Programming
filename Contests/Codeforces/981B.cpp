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
const ll mod = 998244353;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){ 
	fast;
	int n,m;
	cin >> n;
	int a,x;
	map<int,int> mp;
	fore(i,0,n){
		cin >> a >> x;
		mp[a] = x;
	}
	cin >> m;
	fore(i,0,m){
		cin >> a >> x;
		if(mp[a] < x)
			mp[a] = x;
	}
	ll ans = 0;
	fori(i,mp){
		ans += (ll)i->S;
	}
	cout << ans << '\n';
	return 0;
}
    
