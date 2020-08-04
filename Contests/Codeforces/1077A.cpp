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
#define cls(s) s.clear()
#define sz(s) int(s.size())
#define	mst(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 50;
const int mod = 1e9 + 7;
const ll MAX = (1 << 30);
int main(){
	fast;
	int t;
	ll a,b,k;
	cin >> t;
	while(t--){
		cin >> a >> b >> k;
		if(k&1)
			cout << a * (k / 2 + 1) - b * (k / 2) << '\n';
		else
			cout << a * (k / 2) - b * (k / 2) << '\n';
	}
	return 0;	
}
