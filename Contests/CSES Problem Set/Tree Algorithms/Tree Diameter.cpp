#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> G[N];
int vis[N];
void bfs(int nodo){
	queue<int> q;
	q.push(nodo);
	vis[nodo] = 0;
	while(q.size()){
		int u = q.front(); q.pop();
		for(int v : G[u]){
			if(vis[v] == -1){
				vis[v] = vis[u] + 1;
				q.push(v);
			}
		}
	}
}
int main(){
	int n, x;
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(vis, -1, sizeof vis);
	bfs(0);

	int node = max_element(vis, vis + n) - vis;

	memset(vis, -1, sizeof vis);
	bfs(node);

	cout << *max_element(vis, vis + n) << '\n';

	

	
	return 0;
}

