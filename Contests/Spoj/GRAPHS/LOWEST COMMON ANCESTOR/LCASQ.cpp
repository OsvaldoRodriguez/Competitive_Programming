#include <bits/stdc++.h>
using namespace std;

/*
Complexity:
n = vertices
m = aristas

Tiempo:
	dfs    ->	  O((n + m) log n)
	build  ->	  O((n + m) log n)
	equals ->     O(log n)
	lowest_common_ancestor -> O(log n)

Espacio:

	P      		->   O(n log n)
	G, depth    ->  O(n)
*/

struct LCA{

	// LCA para grafos no dirigidos
	int N;
	int LOG;
	// Grafo
	vector<vector<int>> G;
	// P[u][i] = guarda a todos los padres de u que sean potencia de 2 (2^i)
	vector<vector<int>> P;
	// produndidad en el arbol con raiz 0
	vector<int> depth;
	LCA(int n){
		this -> N = n;
		this -> LOG = 31 - __builtin_clz(n) + 1;
		G.assign(N, vector<int>());
		depth.assign(N, 0);
		P.assign(N, vector<int> (LOG + 1));
	}
	void addEdge(int u, int v){
		G[u].push_back(v);
	}

	void dfs(int u, int parent, int prof){
		// guardamos la profundidad de u con raiz 0
		depth[u] = prof;
		// asignamos padre de 2^0 de u
		P[u][0] = parent;
		// calculamos todos los padres de tamaño 2^i
		for(int i = 1; i <= LOG; i++){
			/*
			i - 1 es el padre de potencia 2 ^ (i - 1)
			P[u][i - 1] es el id del nodo padre de u de tamaño 2^(i - 1)
			P[P[u][i - 1]][i - 1] es el padre del padre de u de tamaño 2^(i - 1)
			entonces 2^(i - 1) + 2^(i - 1) = 2 ^ i
			*/
			P[u][i] = P[P[u][i - 1]][i - 1];
		}
		// hacer lo mismo con los demas vertices
		for(int v : G[u]){
			// para no volver atras
			if(v != parent){
				dfs(v, u, prof + 1);
			}
		}
	}

	void build(){
		// dfs(nodo_raiz, padre_nodo_raiz, profundidad)
		dfs(0, 0, 0);
	}

	// equals sube k veces un nodo, la idea se basa en lo siguiente

	/*
	k = 3  binario es:  0000000...011
	entonces como tenemos las potencias de 2^i
	solo necesitamos recorrer los bits del nodo u
	y subir la potencia 2^i del nodo u
	*/
	int equals(int u, int k){
		for(int i = 0; i <= LOG; i++)
			if( (1 << i) & k)
				u = P[u][i];
		
		return u;
	}

	int lowest_common_ancestor(int u, int v){
		if(depth[u] < depth[v])
			swap(u, v);
		u = equals(u, depth[u] - depth[v]);
		// ya es el lca entonces retornamos
		if(u == v)
			return u;
		/*
		caso contrario saltamos potencias de 2^i mientras
		el padre de u y de v de tamaño 2 ^ i no sea el mismo, 
		por que si ese el mismo entonces ya encontramos el lca y es
		P[u][0] o P[v][0] (ya que serian los mismos)
		*/ 

		for(int i = LOG; i >= 0; i--){
			if(P[u][i] != P[v][i]){
				u = P[u][i];
				v = P[v][i];
			}
		}
		// encontramos el lca de (u, v)
		return P[u][0];
	}

	void mostrar(){
		cout << N << "  " << LOG << endl;
		for(int i = 0; i < N; i++){
			cout << i << " -> " ;
			for(int j : G[i])
				cout << j << ", ";
			cout << "\n";
		}

		for(int i = 0; i < N; i++){
			cout << i << "-> ";
			for(int j = 0; j <= LOG; j++){
				cout << P[i][j] << " ";
			}
			cout << "\n";
		}
	}



};
int main(){
	int n;
	cin >> n;
	LCA lca(n);
	for(int i = 0; i < n; i++){
		int len;
		cin >> len;
		for(int j = 0; j < len; j++){
			int x;
			cin >> x;
			lca.addEdge(i, x);
			lca.addEdge(x, i);
		}
	}
	int q;
	cin >> q;
	lca.build();
	while(q--){
		int u, v;
		cin >> u >> v;
		cout << lca.lowest_common_ancestor(u, v) << '\n';
	}
	return 0;
}
