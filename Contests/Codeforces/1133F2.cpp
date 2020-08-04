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
vector<ii> ans;
int k;
int vis[N],comp[N];
void dfs(int u,int mk){
	comp[u] = mk;
	fore(i,0,G[u].size()){
		int v = G[u][i];
		if(comp[v] == -1){
			dfs(v,mk);
		}
	}
}
void bfs(int node){
	vis[node] = 1;
	queue<int> q;
	set<int> aux;
	vector<ii> aux1;
	fore(i,0,G[1].size()){
		int v = G[1][i];
		if(aux.count(comp[v]))
			comp[v] = (1 << 30);
		aux1.pb(ii(comp[v],v));
		aux.insert(comp[v]);
	}
	
	sort(all(aux1));
	fore(i,0,k){
		int v = aux1[i].S;
		q.push(v);
		ans.pb(ii(1,v));
		vis[v] = 1; 
	}
	while(!q.empty()){
		int u = q.front();q.pop();
		fore(i,0,G[u].size()){
			int v = G[u][i];
			if(vis[v] == -1){
				ans.pb(ii(u,v));
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}
int main(){
	//fast;
	int n,m,x,y;
	cin >> n >> m >> k;
	memset(comp,-1,sizeof comp);
	while(m--){
		cin >> x >> y;
		G[x].pb(y);
		G[y].pb(x);
	}
	if(G[1].size() < k){
		cout << "NO\n";
		return 0;
	}
	comp[1] = 0;
	int mk = 1;
	fore(i,0,G[1].size()){
		if(comp[G[1][i]] == -1){
			dfs(G[1][i],mk);
			mk++;
		}
	}

	memset(vis,-1,sizeof vis);
	
		bfs(1);
		bool flag = 1;
		fore(i,1,n + 1)
			if(vis[i] == - 1){
				flag = 0;
				break;
			}
		if(flag){
			cout << "YES\n";
			for(auto i : ans)
				cout << i.F << " " << i.S << "\n";
		}
		else cout << "NO\n";
	
	return 0;	
}
