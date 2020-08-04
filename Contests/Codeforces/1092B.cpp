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
bool vis[N];
vector<int> G[N];
void dfs(int u){
	vis[u] = 1;
	fore(i,0,G[u].size())
		if(!vis[G[u][i]])
			dfs(G[u][i]);
}
int main(){
	fast;
	int n;
	cin >> n;
	int v[n];
	fore(i,0,n)cin >> v[i];
	sort(v,v + n);
	int ans = 0;
	for(int i = 0; i < n; i += 2)
		ans += v[i + 1] - v[i];
	cout << ans << '\n';
	return 0;	
}
