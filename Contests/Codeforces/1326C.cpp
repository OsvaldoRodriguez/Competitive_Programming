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
int v[N];
bool ext[N];
int main(){ 
	int n,k;
	scanf("%d%d",&n,&k);
	fore(i,0,n){
		int x;
		scanf("%d",&x);
		ext[x] = 1;
		v[x] = i;
	}
	int i = N - 1;
	vector<ii> aux;
	while(k > 0){
		if(ext[i]){
			aux.pb({v[i],i});
			k--;
		}
		i--;
	}
	sort(all(aux));
	ll ans_1 = aux[0].S;
	ll ans_2 = 1;
	fore(i,1,sz(aux)){
		ans_1 += aux[i].S;
		ans_2 = (ans_2 % mod * (aux[i].F - aux[i - 1].F) % mod) % mod;
	}
	printf("%lld %lld\n",ans_1,ans_2 );
	return 0;
}
    
