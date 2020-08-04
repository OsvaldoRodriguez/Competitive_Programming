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
	int n;
	cin >> n;
	while(n--){
		bool flag = 0;
		int par = 0;
		string s;
		cin >> s;
		int tmp = 0;
		int c = 0;
		fore(i,0,sz(s)){
			if(s[i] == '0')
				flag = 1,c++;
			else
			if(!((s[i] - '0') & 1))
				par++;
			tmp += (s[i] - '0');
		}
		if( c == sz(s) or (tmp % 3 == 0 && !par && c > 1) or (tmp % 3 == 0 && par && c > 0))
			cout << "red\n";
		else
		cout << "cyan\n"; 
	}
	return 0;
}
