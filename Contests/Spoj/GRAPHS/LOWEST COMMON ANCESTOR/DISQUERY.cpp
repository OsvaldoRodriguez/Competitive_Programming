#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
struct LCA{
 
    // LCA para grafos no dirigidos
    int N;
    int LOG;
    // Grafo
    vector<vector<pair<int, int>>> G;
    // P[u][i] = guarda a todos los padres de u que sean potencia de 2 (2^i)
    vector<vector<int>> P, MX, MN;
    // produndidad en el arbol con raiz 0
    vector<int> depth;
    LCA(int n){
        this -> N = n;
        this -> LOG = 31 - __builtin_clz(n) + 1;
        G.assign(N, vector<pair<int, int>>());
        depth.assign(N, 0);
        P.assign(N, vector<int> (LOG + 1));
        MX.assign(N, vector<int> (LOG + 1));
        // es para minimos
        MN.assign(N, vector<int> (LOG + 1));
    }
    void addEdge(int u, int v, int w){
        G[u].push_back({v, w});
    }
 
    void dfs(int u, int parent, int cost, int prof){
        // guardamos la profundidad de u con raiz 0
        depth[u] = prof;
        // asignamos padre de 2^0 de u
        P[u][0] = parent;
 
        // asignamos el costo de cada arista
        MX[u][0] = cost;
        MN[u][0] = cost;
        // calculamos todos los padres de tamaÃ±o 2^i
        for(int i = 1; i <= LOG; i++){
            /*
            i - 1 es el padre de potencia 2 ^ (i - 1)
            P[u][i - 1] es el id del nodo padre de u de tamaÃ±o 2^(i - 1)
            P[P[u][i - 1]][i - 1] es el padre del padre de u de tamaÃ±o 2^(i - 1)
            entonces 2^(i - 1) + 2^(i - 1) = 2 ^ i
            */
            P[u][i] = P[P[u][i - 1]][i - 1];
            MX[u][i] = max(MX[u][i - 1], MX[ P[u][i - 1] ][i - 1]);
            MN[u][i] = min(MN[u][i - 1], MN[ P[u][i - 1] ][i - 1]);
        }
        // hacer lo mismo con los demas vertices
        for(auto edge : G[u]){
        	int v = edge.first;
        	int w = edge.second;
            // para no volver atras
            if(v != parent){
                dfs(v, u, w, prof + 1);
            }
        }
    }
 
    void build(){
        // dfs(nodo_raiz, padre_nodo_raiz, profundidad)
        dfs(0, 0, 0, 0);
    }
 
    // equals sube k veces un nodo, la idea se basa en lo siguiente
 
    /*
    k = 3  binario es:  0000000...011
    entonces como tenemos las potencias de 2^i
    solo necesitamos recorrer los bits del nodo u
    y subir la potencia 2^i del nodo u
    */
    // (nodo, max) el nodo desde que subio y maximo en su camino
    int equals(int u, int k, int &mn, int &mx){
        for(int i = 0; i <= LOG; i++)
            if( (1 << i) & k){
            	mx = max(mx, MX[u][i]);
            	mn = min(mn, MN[u][i]);
                u = P[u][i];
            }
        
        return u;
    }
 
    // (lca, maximo valor en el camino de u a v)
    // pero primero calcula el max(camino u, lca) y luego 
    // el maximo camino de lca, v
    pair<int, int> lowest_common_ancestor(int u, int v){
    	int mn = 1e9, mx = 0;
        if(depth[u] < depth[v])
            swap(u, v);
        int cur = equals(u, depth[u] - depth[v], mn, mx);
        u = cur;
        // ya es el lca entonces retornamos
        
        if(u == v)
            return {mx, mn};
        /*
        caso contrario saltamos potencias de 2^i mientras
        el padre de u y de v de tamaÃ±o 2 ^ i no sea el mismo, 
        por que si ese el mismo entonces ya encontramos el lca y es
        P[u][0] o P[v][0] (ya que serian los mismos)
        */ 
        for(int i = LOG; i >= 0; i--){
            if(P[u][i] != P[v][i]){
                mx = max({mx, MX[u][i], MX[v][i]});
                mn = min({mn, MN[u][i], MN[v][i]});
                u = P[u][i];
                v = P[v][i];
            }
        }
        // encontramos el lca de (u, v)
        mx = max({mx, MX[u][0], MX[v][0]});
        mn = min({mn, MN[u][0], MN[v][0]});
        return {mx, mn};
    }
 
    void mostrar(){
        cout << N << "  " << LOG << endl;
        for(int i = 0; i < N; i++){
            cout << i  << " -> " ;
            for(auto j : G[i])
                cout << "(" << j.first  << ", " << j.second << ")";
            cout << "\n";
        }
        for(int i = 0; i < N; i++){
            cout << i  << "-> ";
            for(int j = 0; j <= LOG; j++){
                cout << P[i][j]  << " ";
            }
            cout << "\n";
        }
 
        cout << "MAXIMO\n";
        for(int i = 0; i < N; i++){
            cout << i << "-> ";
            for(int j = 0; j <= LOG; j++){
                cout << MX[i][j] << " ";
            }
            cout << "\n";
        }
    }
 
 
 
};
 
struct edges{
	int u, v, w, pos;
	edges(int u, int v, int w, int pos){
		this -> u = u;
		this -> v = v;
		this -> w = w;
		this -> pos = pos;
	}
	bool operator < (const edges &A){
		return w < A.w; 
	}
 
	void mostrar(){
		cout << "(" << u  << ", " << v << ", " << w << ", " << pos << ")";
	}
};
 
 
 
int main(){
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
	int n;
	cin >> n;
	LCA lca(n);
	for(int i = 1; i < n; i++){
		int u, v, w;
		cin >> u >> v >> w;
		--u;
		--v;
		lca.addEdge(u, v, w);
		lca.addEdge(v, u, w);
	}
 
	lca.build();
 
	int q;
	cin >> q;
	while(q--){
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		auto cur = lca.lowest_common_ancestor(u, v);
		cout << cur.second << " " << cur.first << "\n";
	}
    return 0;
} 
