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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){
	int t;
	ll n,k;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld",&n,&k);
		if(k > n){
			printf("NO\n");
			continue;
		}
		if((n & 1) && k == 1){
			printf("YES\n");
			continue;
		}
		ll aux = k * k;
		if(aux <= n){
			if(((n & 1) && (k & 1)) or (!(n & 1) && !(k & 1)) or ((n & 1) && k == 1))
				printf("YES\n");
			else
				printf("NO\n");
		}else
			printf("NO\n");
		

	}
	return 0;
}
    
