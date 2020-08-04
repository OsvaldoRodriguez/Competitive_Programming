#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll f(ll val,int n,int m){
	val--;
	ll ans = 0;
	for(ll i = 1; i <= n; ++i)
		if(m < val/i)
			ans += m;
		else
			ans += val/i;
	return ans;
}
int main(){

	ll n,m,k;
	cin >> n >> m >> k;
	ll a = 1,b = n*m + 1, m1;
	while(b - a > 1){
		m1 = (a + b)>>1;
		if(f(m1,n,m) < k)
			a = m1;
		else
			b = m1;
	}
	cout << a << '\n';

	return 0;
}
