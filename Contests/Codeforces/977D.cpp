#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<long long,long long>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b,inc) for(int i = a;i < b; i+= inc)
#define forr(i,a) for(int i = a; i >= 0; i--)
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
vector<int> G[105];
ll v[105];
int g[105],vis[105];
void dfs(int u){
	vis[u] = 1;
	cout << v[u] << ' ';
	fore(i,0,G[u].size(),1){
		int v = G[u][i];
		if(vis[v] == -1)
			dfs(v);
	}
}
int main(){
	fast;
	int n;
	cin >> n;
	fore(i,0,n,1)
		cin >> v[i];
	fore(i,0,n,1){
		fore(j,0,n,1){
			if(v[i] * 2 == v[j])
				G[i].pb(j),g[j]++;
			else if(v[i] == v[j] * 3)
				G[i].pb(j),g[j]++;
		}
	}
	memset(vis,-1,sizeof vis);
	fore(i,0,n,1)
		if(!g[i]){
			dfs(i);
			break;
		}
	return 0;	
}
