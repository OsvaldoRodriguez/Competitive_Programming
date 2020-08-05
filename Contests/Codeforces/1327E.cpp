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
const ll mod = 998244353;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
ll power(ll a,ll b, ll mod){
	ll ans = 1;
	while(b){
		if(b & 1)
			ans = (a % mod * ans % mod) % mod;
		b >>= 1;
		a = (a % mod * a % mod) % mod;
	}
	return ans;
}
ll solve(ll x){
	if(x == 0)
		return 10LL;
	return ((9 * 9 * x + 99LL) % mod * power(10,x - 1,mod)) % mod;
}
int main(){
	int n;
	scanf("%d",&n);
	fore(i,0,n)
		printf("%lld\n",solve(n - i - 1));

	return 0;
}
    
