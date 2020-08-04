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
const int N = 1 * 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){
	int t;
	scanf("%d",&t);
	ll x;
	while(t--){
		int n;
		int v[3];
		cls(v,0);
		scanf("%d",&n);
		int ans = 0;
		fore(i,0,n){
			ll x;
			scanf("%lld",&x);
			if(x % 3 == 0){
				v[0]++;
				continue;
			}
			ll div = x / 3;
			div++;
			v[div * 3 - x]++;
		}

		ans = v[0];
		int tmp = min(v[1],v[2]);
		ans += tmp;
		v[1] -= tmp;
		v[2] -= tmp;
		ans += v[1] / 3 + v[2] / 3;
		printf("%d\n",ans);
	}
	return 0;
}
