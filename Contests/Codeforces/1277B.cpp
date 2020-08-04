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
#define sz(s) int(s.size())
#define	cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll INF = LONG_LONG_MAX;
ll f(ll x){return x * (x + 1) >> 1;}
vector<int> v;
int main(){
	//fast;
	int t,n;
	cin >> t;
	while(t--){
		v.clear();
		set<int> s;
		cin >> n;
		fore(i,0,n){
			int x;
			cin >> x;
			if(!(x & 1))
				s.insert(x);
		}
		fori(i,s)
			v.pb(*i);
		int ans = 0;
		set<int> tmp;
		if(sz(v)){
			fore(i,0,sz(v)){
				int x = v[i];
				if(x == 0)
					continue;
				while(!(x & 1)){
					x >>= 1;
					tmp.insert(x);
				}
			}
			ans = sz(tmp);
		}
		cout << ans << '\n';
		

	}
	return 0;
}
