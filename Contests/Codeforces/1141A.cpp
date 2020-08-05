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
const ll mod = 10;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){
	fast;
	ll n,m;
	cin >> n >> m;
	ll aux = m / n;
	if(n * aux == m){
		int ans = 0;
		set<ll> s;
		bool flag = 1;
		while(aux > 1){
			s.insert(aux);
			if(aux % 2 == 0)
				aux /= 2,ans++;
			else if(aux % 3 == 0)
				aux /= 3,ans++;
			if(s.count(aux)){
				flag = 0;
				break;
			}
		}
		if(flag)
			cout << ans << '\n';	
		else
			cout << "-1\n";
	}else
		cout << "-1\n";
	return 0;
}
