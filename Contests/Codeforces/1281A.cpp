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
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll INF = LONG_LONG_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
ll f(ll x){return x * (x + 1) >> 1;}
vector<int> v;
int main(){
	fast;
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		string ans = "KOREAN";
		string aux = s.substr(sz(s) - 2,2);
		if(aux == "po")
			cout << "FILIPINO\n";
		else {
			aux = s.substr(sz(s) - 4,4);
			if(aux == "masu" or aux == "desu")
			cout << "JAPANESE\n";
			else
			cout << ans << '\n'; 
	}
}
	return 0;
}
