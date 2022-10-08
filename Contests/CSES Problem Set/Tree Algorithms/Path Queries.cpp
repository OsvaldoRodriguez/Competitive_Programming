#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int v[N];
struct SegTree{
    int N_MAX;
    vector<ll> ST, A;

    SegTree(){

    }
    SegTree(int n, const vector<ll> &B){
        N_MAX = n;
        ST.assign((N_MAX << 2) + 5, 0);
        A = B;
    }
    void build(){
        build(1, 0, N_MAX - 1);
    }
    void build(int node, int a, int b){
        if(a == b)
            ST[node] = A[a];
        else{
            int m = (a + b) >> 1;
            build(left(node), a, m);
            build(right(node), m + 1, b);
            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }
    ll query(int node, int a, int b, int l, int r){
        int m = (a + b) >> 1;
        if(a >= l && b <= r)
            return ST[node];
        if(r <= m)
            return query(left(node), a, m, l, r);
        if(l > m)
            return query(right(node), m + 1, b, l, r);
        return f(query(left(node), a, m, l, r), query(right(node), m + 1, b, l, r));
    }

    void update(int node, int a, int b, int i, int val){
        if(a == b)
            ST[node] = val;
        else{
            int m = (a + b) >> 1;
            if(i <= m)
                update(left(node), a, m, i, val);
            else
                update(right(node), m + 1, b, i, val);
            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }

    void mostrar(){
        for(int i = 0; i < N_MAX; i++)
            cout << i << " " << ST[i] << endl;
    }
    ll get(int i, int j){
        return query(1, 0, N_MAX - 1, i, j);
    }
    void update(int i, ll val){
        update(1, 0, N_MAX - 1, i, val);
    }
    ll f(ll a, ll b){
        return a + b;
    }

    int left(int x){return (x << 1);}
    int right(int x){return (x << 1) | 1;}

};
vector<int> G[N];
struct HLD{
    int N_MAX;
    int nro_cad; // el color de cada chain
    int root;   // raiz del arbol
    int pos; // la posicion de cada nodo para el segment tree
    vector<int> subsize; // tamaño de del subarbol de u
    vector<int> depth;  // profundidad del nodo u respecto a la raiz
    vector<int> parent; // el padre de cada nodo, sirve para para de una cadena a otra
    vector<int> where; // guarda el color del nodo i

    vector<ll> chainIndex; // la posicion en la cadena del nodo i
    vector<int> head; // head[i] guarda quien es la cabeza del chain de color i

    SegTree Tree;

    HLD(int n){
        N_MAX = n;
        N_MAX += 2;
        // asumiendo la raiz como el nodo 0
        subsize.assign(N_MAX, 0);
        depth.assign(N_MAX, 0);
        parent.assign(N_MAX, 0);
        chainIndex.assign(N_MAX, 0);

        // nose sabe a que cadena estara asignado 
        where.assign(N_MAX, -1);
        // no se sabe quien es la cabeza de la cadena
        head.assign(N_MAX, -1);
        root = 0; 
        nro_cad = 0; // la cadena principal tiene color 0
        pos = 0; // posicion de los nodos en el array

        depth[0] = 0;
        dfs(root, -1);
        descomponer(root);
        Tree = SegTree((int)chainIndex.size(), chainIndex);
        Tree.build();
    }

    void dfs(int u, int pu){
        subsize[u] = 1;
        parent[u] = pu;
        for(int v : G[u]){
            if(v == pu)
                continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
            subsize[u] += subsize[v];
        }
    }

    void descomponer(int u){
        if(head[nro_cad] == -1){ // si la cabeza del color de un chain (n_cad) esta en -1 no tiene color asignado
            head[nro_cad] = u;
        }
        where[u] = nro_cad; // asignando color chain al nodo u
        chainIndex[u] = pos++; // estamos vectorizando el arbol, llevando a un vector para el segment tree (pos es la posicion)
        int maxi = -1, special_node = -1;
        // encontrando la arista pesada heavy
        for(int v : G[u]){
            // si  no ha sido asignado un color where[v]
            if(subsize[v] > maxi and where[v] == -1){
                maxi = subsize[v];
                special_node = v;
            }
        }
        // seguir descomponiendo, formando un chain
        if(special_node != -1){
            descomponer(special_node);
        }

        for(int v : G[u]){
            if(where[v] == -1){
                nro_cad++;
                descomponer(v);
            }
        }
    }

    int lca(int u, int v){
        while(where[u] != where[v]){
            if(depth[head[where[u]]] > depth[head[where[v]]])
                u = parent[head[where[u]]];
            else
                v = parent[head[where[v]]];

        }
        return depth[u] < depth[v] ? u : v;
    }


    ll query(int u, int v){
        int colorV = where[v];
        ll ans = 0;
        // asumimos que U es el nodo que esta mas profundo
        while(true){
            // siempre sube U
            int colorU = where[u];
            if(colorU == colorV){
                return ans = f(ans, Tree.get(chainIndex[v], chainIndex[u]));
            }
            int hu = head[colorU];
            ans = f(ans, Tree.get(chainIndex[hu], chainIndex[u]));
            u = parent[hu]; 
        }
        return ans;
    }

    ll get(int u, int v){
        int L = lca(u, v);
        ll ans = f(query(u, L), query(v, L));
        ans = finv(ans, query(L, L)); // como el lca suma dos veces se quita una vez con el inverso
        return ans;
    }

    void update(int u, int val){
        Tree.update(chainIndex[u], val);
    }

    ll f(ll a, ll b){
        return a + b;
    }

    ll finv(ll a, ll b){
        return a - b;
    }

};


int main(){
    // problem 1 
    // update node u with val v
    // query sum_values(u, v)
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    for(int i = 1, u, v; i < n; ++i){
        cin >> u >> v;
        --u;
        --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    HLD hld(n);
    hld.Tree.build();
    for(int i = 0; i < n; i++){
        hld.update(i, v[i]);
    }
    while(q--){
        int t, u, v;
        cin >> t;
        if(t == 1){
            cin >> u >> v;
            hld.update(u - 1, v);
        }else{
            cin >> v;
            cout << hld.get(0, v - 1) << "\n";
        }
    }

    return 0;
}
