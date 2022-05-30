#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int SZ[N];
// Problema para cada nodo u calcular su subtree
void dfs(int u, int p, vector<vector<int>> &G){
	SZ[u] = 1;
	for(int v : G[u]){
		if(p == v)
			continue;
		dfs(v, u, G);
		// despues de procesar v 
		// entonces el tamaño de u es += el tamaño de v
		SZ[u] += SZ[v];
	}
}
int main(){
	int n, x;
	cin >> n;
	vector<vector<int>> G(n + 1, vector<int>());
	for(int i = 1; i < n; i++){
		cin >> x;
		// x--;
		G[i + 1].push_back(x);
		G[x].push_back(i + 1);
	}

	dfs(1, 1, G);
	for(int i = 1; i <= n; i++){
		cout << SZ[i] - 1 << " ";
	}
	cout << "\n";

	
	return 0;
}

