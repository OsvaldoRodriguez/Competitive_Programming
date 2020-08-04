#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1 << 30);
vector<string> v;
set<string> s;
map<string,int> m;
int main(){
	fast;
	ll t,n;
	cin >> t;
	while(t--){
		cin >> n;
		set<ll> s;
		s.insert(0);
		s.insert(1);
		s.insert(n);
		for(ll i = 2; i * i <= n; i++){
			s.insert(i);
			s.insert(n / i);	
		}
		cout << s.size() << '\n';
		fori(i,s)
			cout << *i << ' ';
		cout << '\n';
	}

	return 0;	
}
