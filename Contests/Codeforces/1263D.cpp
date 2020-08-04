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
	string s;
	cin >> n;
	mst(vis,0);
	fore(i,0,n){
		cin >> s;
		for(auto c:s){
			G[c - 'a' + 200000].pb(i);
			G[i].pb(c - 'a' + 200000);
		}
	}
	int ans = 0;
	fore(i,0,n){
		if(!vis[i] && sz(G[i]) > 0){
			dfs(i);
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;	
}
