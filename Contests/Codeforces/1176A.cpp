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
		bool flag = 1;
		scanf("%lld",&x);
		ll ans = 0;
		while(x != 1){

			if(!(x & 1))
				x >>= 1;
			else if(x % 3 == 0)
				x = (2LL * x) / 3;
			else if(x % 5 == 0)
				x = (4LL * x) / 5;
			else
				break;
			ans++;
		}
		if(x == 1)
			printf("%lld\n",ans );
		else
			printf("-1\n");
	}
	return 0;
}
