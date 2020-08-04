#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
vector<int> G[N];
int vis[N];
void bfs(int node){
	vis[node] = 1;
	queue<int> q;
	q.push(node);
	while(!q.empty()){
		int u = q.front();q.pop();
		fore(i,0,G[u].size()){
			int v = G[u][i];
			if(vis[v] == -1){
				cout << u << " " << v << '\n';
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}
int main(){
	fast;
	int n,m,x,y;
	cin >> n >> m;
	memset(vis,-1,sizeof vis);
	while(m--){
		cin >> x >> y;
		G[x].pb(y);
		G[y].pb(x);
	}
	int idx = - 1;
	int mx = 0;
	fore(i,1,n + 1){
		if(G[i].size() > mx){
			mx = G[i].size();
			idx = i;
		}
	}
	bfs(idx);
	return 0;	
}
