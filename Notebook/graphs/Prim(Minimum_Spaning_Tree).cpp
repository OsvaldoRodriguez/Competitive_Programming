#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> il;///para el grafo
typedef pair<ll,int> li;///para el set
typedef vector<il> vil;
vector<vil> G;
///para ordenar de acuerdo al peso (costo,nodo)
set<li> S;
///para ver si es parte del mst 1->si 0->no
vector<bool> V;
int n, m;
/// st->nodo enviado , n tam grafo

/*
Complexity:
n = vertex
m = egdes
Time: 
    prim()    -> O(m log n)
*/
ll prim(int st, int n){
    V.assign(n, 0);
    ///el primero en colocar
    S.insert(li(0, st));
    int a, b;///para los nodos
    ll cost, t = 0;
    while(!S.empty()){
        li elem = *S.begin();
        S.erase(S.begin());
        a = elem.second;
        cost = elem.first;
        if(V[a])continue;///si ya lo visitamos no es necesario añadir al set
        t += cost;
        V[a] = 1;
        for(int i = 0; i < G[a].size(); i++){
            b = G[a][i].first;
            cost = G[a][i].second;
            if(!V[b])
                S.insert(li(cost, b));

        }
    }
    return t;
}
int main(){
    int c, a, b;
    cin >> n >> m;
    ///para limpiar el vector cuando es dinamico se usa   (tam,valor)
    G.assign(n, vil());
    for(int i = 0; i < m; i++)
    {
        cin>> a >> b >> c;
        a--; b--;///idexando desde 0
        G[a].push_back(il(b, c));
        G[b].push_back(il(a, c));
    }
    cout << prim(0, m) << "\n";
    return 0;
}
