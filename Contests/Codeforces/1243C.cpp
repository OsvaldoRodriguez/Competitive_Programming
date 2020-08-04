#include <bits/stdc++.h>
#define endl '\n' 
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
const int N = 35 + 5;
const int mod = 1e9 + 7;
const ll MAX = INT_MAX;
set<ll> s;
void f(ll x){
	if( x % 2 == 0){
		s.insert(2);
		while( x % 2 == 0)
			x /= 2;
	}
	for(ll i = 3; i * i <= x; i += 2)
		if(x % i == 0){
			s.insert(i);
			while(x % i == 0)
				x /= i;
		}
	if(x > 2)
		s.insert(x);
}
int main(){
	fast;
	ll n;
	cin >> n;
	f(n);
	if(s.size() > 1)
		cout << 1;
	else
		if(s.empty())
			cout << 1;
		else	
		cout << *s.begin();
	cout << '\n';
	
		
	return 0;
	
}
