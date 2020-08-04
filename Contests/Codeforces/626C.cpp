#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll n,m;
bool f(ll x){
	if(n + m <= x/2 + x/3 -x/6 && n <= x/2 && m <= x/3)
		return 1;
	return 0;
}
int main(){
	while(cin >> n >> m){
		ll a = 0,b = 1000000000, m;
		while(b - a > 1){
			m = (a + b) >> 1;
			if(f(m))
				b = m;
			else
				a = m;
		}
		cout << b << '\n';
	}
	return 0;
}
