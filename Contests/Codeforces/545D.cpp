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
ll v[N],acc[N];
int main(){
	fast;
	int n;
	cin >> n;
	fore(i,0,n)
		cin >> v[i];
	v[n] = LONG_LONG_MAX;
	sort(v,v + n + 1);
	acc[0] = v[0];
	int ans = 0;
	fore(i,1,n + 1){
		if(v[i] >= acc[i - 1])
			ans++;
		else
			v[i] = 0;
		acc[i] = acc[i - 1] + v[i];
	}
	
		cout << ans << '\n';
	return 0;
}
    
