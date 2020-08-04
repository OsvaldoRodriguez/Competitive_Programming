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
#define cls(s) s.clear()
#define sz(s) int(s.size())
#define	mst(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll INF = LONG_LONG_MAX;
int main(){
	fast;
	int t;
	string a,b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		string ans = "NO";
		if(sz(a) > sz(b)){
			cout << "NO\n";
			continue;
		}
		sort(all(a));
		fore(i,0,sz(b) - sz(a) + 1){
			string x = b.substr(i,sz(a));
			sort(all(x));
			if(a == x)
				ans = "YES";
		}
		cout << ans << '\n';
	}
	return 0;	
}
