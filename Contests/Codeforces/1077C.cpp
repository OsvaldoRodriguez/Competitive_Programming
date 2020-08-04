#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<long long,long long>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define cls(s) s.clear()
#define sz(s) int(s.size())
#define	mst(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 50;
const int mod = 1e9 + 7;
const ll MAX = (1 << 30);
vector<ii> v;
int main(){
	fast;
	int n;
	ll x;
	cin >> n;
	ll sum = 0;
	fore(i,0,n){
		cin >> x;
		sum += x;
		v.pb(ii(x,i));
	}
	sort(v.rbegin(),v.rend());
	vector<int> ans;
	ll mx = 0;
	fore(i,0,n){
		if(i == 0)
			mx = v[1].F;
		else mx = v[0].F;
		if(sum - v[i].F == 2 * mx)
			ans.pb(v[i].S);
	}
	cout << sz(ans) << '\n';
	if(sz(ans) > 0)
	for(auto i : ans)
		cout << i + 1 << ' ';
	return 0;	
}
