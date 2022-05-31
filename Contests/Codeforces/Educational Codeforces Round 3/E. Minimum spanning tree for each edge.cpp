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
    vector<vector<int>> P, MX;
    // produndidad en el arbol con raiz 0
    vector<int> depth;
    LCA(int n){
        this -> N = n;
        this -> LOG = 31 - __builtin_clz(n) + 1;
        G.assign(N, vector<pair<int, int>>());
        depth.assign(N, 0);
        P.assign(N, vector<int> (LOG + 1));
        MX.assign(N, vector<int> (LOG + 1));
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

        // calculamos todos los padres de tamaño 2^i
        for(int i = 1; i <= LOG; i++){
            /*
            i - 1 es el padre de potencia 2 ^ (i - 1)
            P[u][i - 1] es el id del nodo padre de u de tamaño 2^(i - 1)
            P[P[u][i - 1]][i - 1] es el padre del padre de u de tamaño 2^(i - 1)
            entonces 2^(i - 1) + 2^(i - 1) = 2 ^ i
            */
            P[u][i] = P[P[u][i - 1]][i - 1];
            MX[u][i] = max(MX[u][i - 1], MX[ P[u][i - 1] ][i - 1]);
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
    pair<int, int> equals(int u, int k){
    	int mx = 0;
        for(int i = 0; i <= LOG; i++)
            if( (1 << i) & k){
            	mx = max(mx, MX[u][i]);
                u = P[u][i];
            }
        
        return {u, mx};
    }

    // (lca, maximo valor en el camino de u a v)
    // pero primero calcula el max(camino u, lca) y luego 
    // el maximo camino de lca, v
    pair<int, int> lowest_common_ancestor(int u, int v){
        if(depth[u] < depth[v])
            swap(u, v);
        auto cur = equals(u, depth[u] - depth[v]);
        u = cur.first;
        // ya es el lca entonces retornamos
        
        int mx = cur.second;
        if(u == v)
            return {u, mx};
        /*
        caso contrario saltamos potencias de 2^i mientras
        el padre de u y de v de tamaño 2 ^ i no sea el mismo, 
        por que si ese el mismo entonces ya encontramos el lca y es
        P[u][0] o P[v][0] (ya que serian los mismos)
        */ 
        for(int i = LOG; i >= 0; i--){
            if(P[u][i] != P[v][i]){
                mx = max({mx, MX[u][i], MX[v][i]});
                u = P[u][i];
                v = P[v][i];
            }
        }
        // encontramos el lca de (u, v)
        return {P[u][0], max({mx, MX[u][0], MX[v][0]})};
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


int P[N], rnk[N];
ll vis[N];
int _find(int u){return (u == P[u] ? u : P[u] = _find(P[u]));}
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
	int n, m;
	cin >> n >> m;
	LCA lca(n);
	vector<edges> A(m, edges(0, 0, 0, 0));

	for(int i = 0; i < m; i++){
		A[i].pos = i;
		cin >> A[i].u >> A[i].v >> A[i].w;
		A[i].u -= 1;
		A[i].v -= 1;
	}
	sort(A.begin(), A.end());

	// for(int i = 0; i < m; i++){
	// 	A[i].mostrar();
	// 	cout << endl;
	// }

	for(int i = 0; i < n; i++){
		P[i] = i;
		rnk[i] = 0;
	}

	ll mst = 0;
	for(int i = 0; i < m; i++){
		int u = A[i].u;
		int v = A[i].v;
		ll w = A[i].w;
		int pos = A[i].pos;
		int pu = _find(u);
		int pv = _find(v);
		if(pv != pu){
			// A[i].mostrar();
			// cout << endl;
			vis[pos] = 1;
			if(rnk[pu] > rnk[pv])
				swap(pu, pv);

			P[pu] = pv;
			if(rnk[pu] == rnk[pv])
				rnk[pv]++;
			lca.addEdge(u, v, w);
			lca.addEdge(v, u, w);
			mst += w;
		}
	}
	lca.build();
	// lca.mostrar();

	for(int i = 0; i < m; i++){
		if(vis[A[i].pos] == 1){
			vis[A[i].pos] = mst;
		}else{
			// A[i].mostrar();
			// cout << " ";
			auto cur = lca.lowest_common_ancestor(A[i].u, A[i].v);
			// cout << cur.first << ' ' << cur.second << endl;
			// al mst le quitamos la arista mas grade y le ponemos A[i]
			vis[A[i].pos] = mst - (ll)cur.second + (ll)A[i].w; 

		}
	}

	for(int i = 0; i < m; i++)
		cout << vis[i] << "\n";
    return 0;
}
