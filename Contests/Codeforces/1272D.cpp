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
ll f(ll x){return x * (x + 1) >> 1;}
int v[N],pr[N],sf[N];
int main(){
	fast;
	int n;
	cin >> n;
	fore(i,0,n){
		cin >> v[i];
		pr[i] = 1;
		sf[i] = 1;
	}
	int mx = 1;
	fore(i,1,n)
		if(v[i] > v[i - 1])
			pr[i] = pr[i - 1] + 1;
	
	for(int i = n - 1; i > 0; i--)
		if(v[i - 1] < v[i])
			sf[i - 1] = sf[i] + 1;
	
	fore(i,0,n)
		mx = max(mx,max(pr[i],sf[i]));

	int ans = max(pr[n - 1],sf[0]);
	fore(i,1,n - 1)
		if(v[i - 1] < v[i + 1])
		ans = max(ans,pr[i - 1] + sf[i + 1]);
	
	cout << max(ans,mx) << '\n';
	return 0;
}
