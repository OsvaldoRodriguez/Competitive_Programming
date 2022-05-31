#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct LCA{
	/*
	la idea central del algoritmo es llevar a RMQ
	euler -> el vector que guarda el id los nodos en el recorrido de euler
	el tamaÃ±o del vector euler es 2 * N - 1
	depth -> es el nivel en el que esta cada nodo en el vector euler[i] respecto a la raiz (0)
	tamaÃ±o del vetctor es 2 * N - 1
	first -> la primera ocurrencia del nodo i en el vector de euler (cualquier ocurrencia es buena, pero se considera el primero)
	*/
	// tamaÃ±o de nodos
	int N;
	vector<vector<int>> G;
	vector<int> euler, depth, first, ST;
	LCA(int n){
		this -> N = n;
		G.assign(N, vector<int>());
		euler.reserve(2 * N);
		depth.reserve(2 * N);
		first.assign(N, -1);
 
	}
 
	void addEdge(int u, int v){
		G[u].push_back(v);
	}
 
	void build(){
		dfs(0, 0, 0);
		// asignamos tamaÃ±o al ST
		int m = euler.size();
		ST.assign((m << 2) + 2, 0);
		build(1, 0, m - 1);
	}
	void dfs(int u, int parent, int prof){
		// adicionamos el nodo u al camino de euler
		euler.push_back(u);
		// adiciona la profundidad del nodo
		depth.push_back(prof);
		// ponemos la primera aparicion de u en el vector de euler (index 0)
		first[u] = euler.size() - 1;
		for(int v : G[u]){
			if(v == parent)
				continue;
			dfs(v, u, prof + 1);
			// despues de procesar un hijo de u, cuando vuelve adicionamos u al camino de euler y adicionamos su profundidad
			euler.push_back(u);
			depth.push_back(prof);
		}
	}
	// segment tree guarda la posicion del minimo
	void build(int node, int l, int r){
        if(l == r){
            ST[node] = l;
        }else{
            int m = (l + r) >> 1;
            build(left(node), l, m);
            build(right(node), m + 1, r);
            // guarda la posicion del minimo
            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }
    void update(int pos, int val){
        update(1, 0, (int) euler.size() - 1, pos, val);
    }
    void update(int node, int l, int r, int pos, int val){
        if(l == r){
            euler[pos] = val;
        }else{
            int m = (l + r) >> 1;
            if(pos <= m)
                update(left(node), l, m, pos, val);
            else
                update(right(node), m + 1, r, pos, val);
 
            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }
    int query(int L, int R){
    	// devuelve el indice del nodo mas arriba en el vector depth
        return  query(1, 0, (int) euler.size() - 1, L, R);
    }
    int query(int node, int l, int r, int L, int R){
        if(l >= L and  r <= R)
            return ST[node];
 
        int m = (l + r) >> 1;
        if(R <= m)
            return query(left(node), l, m, L, R);
        if(L > m)
            return query(right(node), m + 1, r, L, R);
        return f(query(left(node), l, m, L, R), query(right(node), m + 1, r, L, R));
    }
 
    int left(int x){return (x << 1);}
    int right(int x){return ((x << 1) | 1);}
    int f(int a, int b){
        return (depth[a] < depth[b] ? a : b);
    }
 
	int lowest_common_ancestor(int u, int v){
		// hallamos donde ocurren por primera vez u y v
 
		// si la ocurrencia de u es mayor a v, un swap
		if(first[u] > first[v])
			swap(u, v);
 
		// posicion donde esta el minimo
		int pos = query(first[u], first[v]);
		// retornamos el id del nodo el cual es el lca de u y v
		return euler[pos];
	}
 
	void mostrar(){
		for(int i = 0; i < euler.size(); i++){
			cout << i << " " << euler[i] << " " << depth[i] << endl;
		}
		cout << "\n";
 
 
		for(int i = 0; i < first.size(); i++){
			cout << i << " " << first[i] << endl;
		}
 
	}
};
 
int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// int n;
	// cin >> n;
	// // index 0
	// LCA lca(n);
	// for(int i = 1; i < n; i++){
	// 	int u, v;
	// 	cin >> u >> v;
	// 	lca.addEdge(u, v);
	// 	lca.addEdge(v, u);
	// }
	// lca.build();
 
	// while(true){
	// 	int a, b;
	// 	cin >> a >> b;
	// 	cout << lca.lowest_common_ancestor(a, b) << endl;
	// }
 
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
