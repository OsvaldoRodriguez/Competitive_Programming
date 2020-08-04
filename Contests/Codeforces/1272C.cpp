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
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const ll INF = LONG_LONG_MAX;
ll f(ll x){return x * (x + 1) >> 1;}
bool v[26];
int main(){
	fast;
	int t,n;
	string s;
	cin >> t >> n >> s;
	fore(i,0,n){
		char x ;
		cin >> x;
		v[x - 'a'] = 1;
	}
	ll ans = 0;
	fore(i,0,sz(s)){
		int j = i;
		while(v[s[j] - 'a'] &&  i < sz(s))
			j++;
		ll tmp = j - i;
		ans += f(tmp);
		i = j;
	}
	cout << ans << '\n';
	return 0;	
}
