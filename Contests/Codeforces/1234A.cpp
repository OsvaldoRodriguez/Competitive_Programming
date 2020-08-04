#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long ll;
const int N = 104;
ll n,sum;
bool f(ll x){
	if(x * n >= sum)
		return 1;
	return 0;
}
int main(){
	int t,x;
	cin >> t;
	while(t--){
		cin >> n;
		sum = 0;
		for(int i = 0; i < n; i++){
			cin >> x;
			sum += x;
		}
		ll a = 0,b = (1<<30), m;
		//cout << b << endl;
		while(b - a > 1){
			m = ( a + b) >> 1;
			//cout << m << endl;
			if(f(m))
				b = m;
			else
				a = m;
		}
		cout << b << '\n';

	}
	return 0;
}
