#include <bits/stdc++.h>
using namespace std;
const int LOG = 30;
const int N = 1000005;
vector<int> G[N];
//LCA para graphs unidirected O(log n)
int P[N][LOG];//guardará a los padres 1<<i (potencias de 2) de cada nodo
int pro[N];
int n;


/*
n = vertex
m = edges
h = altura del arbol
Complexity
Time:
    dfs()   ->  O((n + m) * log(n))
    igualarPro  ->  O(log (n))
    LCA     ->  O(log (h))
    
*/
//dfs para procesar la tabla de padres
/*
cada indice de la tabla guarda un padre de potencia 2
y para saber cual es el padre de potencia 2 solo voy al padre de mi padre
*/
void dfs(int u,int padre,int profundidad){
  P[u][0] = padre;
  pro[u] = profundidad;
  for(int i = 1; i < LOG; i++)
    P[u][i] = P[P[u][i - 1]][i - 1];//voy al padre de mi padre de potencia 2
  for(int i = 0; i <G [u].size(); i++){
    int v = G[u][i];
    if(v != padre)//para no volver atras
      dfs(v, u, profundidad + 1);
  }
}
/*
k es la dif para que el nodo mas bajo suba k niveles
de profundidad como la tabla esta por potencias de dos
solo el binario del nro k es lo que tiene que subir
el nodo u para estar a la misma profundidad
*/
int igualarPro(int u,int k){
  for(int i = 0; i < LOG; i++){
    if((1 << i) & k)
      u = P[u][i];
  }
  return u;
}
int LCA(int u,int v){
  int prou = pro[u];
  int prov = pro[v];
  if(prou > prov)
    u = igualarPro(u, prou - prov);
  if(prov > prou)
    v = igualarPro(v, prov - prou);
  if(u == v)return u;
  for(int i = LOG - 1; i >= 0; i--){
    if(P[u][i] != P[v][i]){//sube hasta 1 antes del ancestro comun mas bajo
      //si es que son iguales es que ya encontro el LCA
      u = P[u][i];
      v = P[v][i];
    }
  }
  return P[u][0];
}
int main(){
  int a, b, t;
  cin >> n;
  for(int i = 1; i < n; i++){
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(0, 0, 0);
  cin >> t;
  while(t--){
    cin>> a >> b;
    cout << LCA(a, b) << '\n';
  }
  return 0;
}
