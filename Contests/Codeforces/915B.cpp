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
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){
	fast;
	int n,pos,l,r;
	cin >> n >> pos >> l >> r;
	if(l == 1 && r == n)
		cout << "0\n";
	else{
		int ans = 1 << 30;
		if((l == 1 && r != n))
			ans = min(ans,abs(pos - r) + 1);
		else if(r == n && 1 != l)
			ans = min(ans,abs(pos - l) + 1);
		else if(1 != l && n != r)
			ans = min(ans,r - l + min(abs(pos - l),abs(pos - r)) + 2);
		cout << ans << '\n';
	}
	return 0;
}
    
