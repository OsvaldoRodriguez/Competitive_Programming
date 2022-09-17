#include <bits/stdc++.h>
using namespace std;
const int N =10000;
vector<int> G[N];
int n, m, tiempo = 1;
int T[N], L[N], P[N];//T,L seteados en 0's P seteado en -1
void dfs(int u){
  cout << u << " dfs\n";
  int children = 0; //para verificar con la raiz
  T[u] = L[u] = tiempo++;
  for(int i = 0; i < G[u].size(); i++){
    int v = G[u][i];
    if(!T[v]){//se usa T como vis o no a  la vez como tiempo
      children++;
      P[v] = u;
      dfs(v);
      L[u] = min(L[u], L[v]);//no interesa si va antes o despues
      //verificar si la raiz es punto de articulacion
      if(P[u] == -1 && children > 1){
        cout<< u <<" punto de articulacion raiz\n";
      }

      // verificar si algun hijo es punto de articulacion
      if(L[v] >= T[u] && P[u] != -1){//P[u] para ver que no es raiz
        cout << u << " punto de articulacion \n";
      }
      //para el caso de puntos de articulacion mejor si se guarda en un vector si es o no es punto de articulacion para evitar posibles valores iguales como en el ejmplo de abajo
      //para verificar si es puente de articulacion
      if(L[v] > T[u]){
        cout << u << " " << v <<" puente de articulacion\n";
      }
    }
    else{
      if(v != P[u]){
        //back edge
        cout<< v <<" ciclo\n";
        L[u] = min(L[u], T[v]);
      }

    }
  }
}
int main(){
  int a,b;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  memset(P,-1,sizeof P);
  for(int i = 1; i < n; i++){
    if(!T[i])
      dfs(i);
  }
  for(int i = 0; i < n; i++)
    cout << i << " " << T[i] << " " << L[i] <<"\n";

}
/*
7 8
0 2
2 1
0 1
1 3
1 4
3 5
4 5
6 1


caso 2
20 26
19 17
17 18
19 18
18 20
16 15
15 14
14 16
14 13
13 1
1 0
0 2
2 3
3 1
3 4
1 4
4 5
5 6
3 7
3 8
8 9
9 10
10 12
10 11
11 10
11 9
8 7
*/
