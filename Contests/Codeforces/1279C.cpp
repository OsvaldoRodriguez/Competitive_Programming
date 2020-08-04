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
ll v[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		ll ans = 0;
		fore(i,0,n){
			int x;
			scanf("%d",&x);
			v[x] = i;
		}
		int x;
		scanf("%d",&x);
		ans = 2LL * ll(v[x]) + 1;
		int pos = v[x];
		fore(i,1,m){
			scanf("%d",&x);
			int tmp_pos = v[x];
			if(tmp_pos <= pos)
				ans++;
			else
				ans += 2LL * ll(v[x] - i) + 1LL, pos = v[x];
		}
		printf("%lld\n",ans);

	}
	return 0;
}
