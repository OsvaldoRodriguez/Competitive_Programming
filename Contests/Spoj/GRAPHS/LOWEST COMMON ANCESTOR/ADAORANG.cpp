#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
 
/*
obs 1: en los arboles hay solo un camino de u a v
obs 2: ahora como se quiere encontrar todos los tipos que existen en los subtrees de un nodo
i donde i es parte del camino de u a v, se puede ver facilmente que el lca de u, v cubre todos
los subtrees del camino 
obs 3: calcular los numeros distintos en cada subtree con un dfs
*/
const int M = 256;
struct LCA{
 
    // LCA para grafos no dirigidos
    int N;
    int LOG;
    // Grafo
    vector<bitset<M>> branch, subtree;
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
        subtree.assign(N, bitset<M>());
        P.assign(N, vector<int> (LOG + 1));
 
    }
    void addEdge(int u, int v){
        G[u].push_back(v);
    }
    void addBranch(int x){
        bitset<M> v;
        v.set(x, 1);
        branch.push_back(v);
    }
    void dfs(int u, int parent, int prof){
        // guardamos la profundidad de u con raiz 0
        depth[u] = prof;
        // asignamos padre de 2^0 de u
        P[u][0] = parent;
 
 
        // para subtree 
        // la raiz del subtree
        subtree[u] = branch[u];
 
        // calculamos todos los padres de tamaÃ±o 2^i
        for(int i = 1; i <= LOG; i++){
            /*
            i - 1 es el padre de potencia 2 ^ (i - 1)
            P[u][i - 1] es el id del nodo padre de u de tamaÃ±o 2^(i - 1)
            P[P[u][i - 1]][i - 1] es el padre del padre de u de tamaÃ±o 2^(i - 1)
            entonces 2^(i - 1) + 2^(i - 1) = 2 ^ i
            */
            P[u][i] = P[P[u][i - 1]][i - 1];
 
        }
        // hacer lo mismo con los demas vertices
        for(auto v : G[u]){
        	if(v != parent){
                dfs(v, u, prof + 1);
                // colocando los valores de los hijos de u
                subtree[u] |= subtree[v];
            }
        }
    }
 
    void build(int root){
        // dfs(nodo_raiz, padre_nodo_raiz, profundidad)
        dfs(root, root, 0);
    }
 
    // equals sube k veces un nodo, la idea se basa en lo siguiente
 
    /*
    k = 3  binario es:  0000000...011
    entonces como tenemos las potencias de 2^i
    solo necesitamos recorrer los bits del nodo u
    y subir la potencia 2^i del nodo u
    */
    // (nodo, max) el nodo desde que subio y maximo en su camino
    int equals(int u, int k){
        for(int i = 0; i <= LOG; i++)
            if( (1 << i) & k){
            	u = P[u][i];
            }
        
        return u;
    }
 
    // (lca, maximo valor en el camino de u a v)
    // pero primero calcula el max(camino u, lca) y luego 
    // el maximo camino de lca, v
    pair<int, bitset<M>> lowest_common_ancestor(int u, int v){
        if(depth[u] < depth[v])
            swap(u, v);
        int cur = equals(u, depth[u] - depth[v]);
        u = cur;
        // ya es el lca entonces retornamos
        
        if(u == v)
            return {u, subtree[u]};
        /*
        caso contrario saltamos potencias de 2^i mientras
        el padre de u y de v de tamaÃ±o 2 ^ i no sea el mismo, 
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
        int node_lca = P[u][0];
        // retornamos el lca y el bitset del lca (ahi esta los tipos diferentes de naranjas)
        return {P[u][0], subtree[node_lca]};
    }
 
    void mostrar(){
 
        cout << "values\n";
        for(int i = 0; i < (int)subtree.size(); i++){
            cout << i << " " << branch[i] << "\n";
        }
        cout << "bitset\n";
        for(int i = 0; i < (int)subtree.size(); i++){
            cout << i << " " << subtree[i] << "\n";
        }
        cout << N << "  " << LOG << endl;
        for(int i = 0; i < N; i++){
            cout << i  << " -> " ;
            for(auto j : G[i])
                cout << "(" << j << ")";
            cout << "\n";
        }
        for(int i = 0; i < N; i++){
            cout << i  << "-> ";
            for(int j = 0; j <= LOG; j++){
                cout << P[i][j]  << " ";
            }
            cout << "\n";
        }
 
    }
 
 
 
};
 
int main(){
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
    int t, x, n, m, root;
    cin >> t;
    while(t--){
        cin >> n >> m >> root;
        LCA lca(n);
        for(int i = 0; i < n; i++){
            cin >> x;
            lca.addBranch(x);
 
        }
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            lca.addEdge(u, v);
            lca.addEdge(v, u);
        }
 
        lca.build(root);
        // lca.mostrar();
        while(m--){
            int u, v;
            cin >> u >> v;
            // cout << u << " " << v << " ";
            auto cur = lca.lowest_common_ancestor(u, v);
            cout << cur.second.count() << "\n";
 
        }
 
    }
    
	
    return 0;
} 
