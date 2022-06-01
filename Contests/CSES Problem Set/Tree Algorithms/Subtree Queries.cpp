#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

ope1: cambiar el valor del nodo s por x
ope2: hallar el valor del subtree de x sabiendo que esta roteado en 1
obs: el arbol esta rooteado en 1
idea de la solucion


hacer un recorrido del grafo y guardar el tamaño del subtree de cada nodo
y luego usando FT hacer consultas y actualizacion


    nodo_id:    1   2   3   4   5
    subtree:    5   1   3   1   1 
    valor:      4   2   5   2   3


entonces si queremos calcular la suma del subtree de 3, el vector subtree
indica el tamaño asi que empezando del nodo 3 hasta 3 + subtree[3] = 3 
en ese rango se puede calcular la suma del subtree de 3
como tenemos que hacer updates y queries se puede usar Fenwick Tree

todo sera index 1, por Fenwick Tree
*/
// guarda la posicion del nodo i del vector nodo_id
vector<int> pos;
vector<vector<int>> G;
vector<int> valor, new_valor(1);
vector<int> subtree, oficial_subtree(1);
vector<int> nodo_id;
vector<ll> fenwick_tree;
int n;
void update(int pos, int val){
    for(int i = pos; i <= n; i += i&(-i))
        fenwick_tree[i] += val;
}

ll get(int pos){
    ll sum = 0;
    for(int i = pos; i >= 1; i -= i&(-i))
        sum += fenwick_tree[i];
    return sum;
}
void dfs(int u, int p){
    subtree[u] = 1;
    nodo_id.push_back(u);
    pos[u] = nodo_id.size();
    for(int v : G[u]){
        if(v == p)
            continue;
        dfs(v, u);
        subtree[u] += subtree[v];
    }
}
int main(){

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int m;
    cin >> n >> m;
    G.assign(n + 1, vector<int>());
    valor.assign(n + 1, 0);
    subtree.assign(n + 1, 0);
    fenwick_tree.assign(n + 1, 0);
    pos.assign(n + 1, -1);
    for(int i = 1; i <= n; i++)
        cin >> valor[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);

    for(int i = 0; i < nodo_id.size(); i++){
        oficial_subtree.push_back(subtree[nodo_id[i]]);
        new_valor.push_back(valor[nodo_id[i]]);
    }
    // cout << "pos nodo_id subtree valor\n";
    // for(int i = 1; i <= n; i++)
    //     printf("%3d ", pos[i]);

    // cout << endl;

    // for(int i = 0; i < nodo_id.size(); i++)
    //     printf("%3d ", nodo_id[i]);

    // cout << endl;
    // for(int i = 1; i <= n; i++)

    //     printf("%3d ", oficial_subtree[i]);


    
    // cout << endl;


    // for(int i = 1; i <= n; i++)
    //     printf("%3d ", new_valor[i]);
    // cout << endl;

    for(int i = 1; i <= n; i++)
        update(i, new_valor[i]);


    while(m--){
        int ope, u, v;
        cin >> ope >> u;
        int idx = pos[u];
        // cout << "pos " << u << " " << idx << endl;
        if(ope == 2){
            ll ans = get(idx + oficial_subtree[idx] - 1) - get(idx - 1);
            cout << ans << '\n';
        }else{
            cin >> v;
            // le quito lo que tenia
            update(idx, -new_valor[idx]);
            // actualizo el valor en el vector
            new_valor[idx] = v;
            // le pongo el nuevo valor
            update(idx, new_valor[idx]);

        }
    }


    return 0;
}
