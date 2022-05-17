#include <bits/stdc++.h>
using namespace std;
const int  N = 1e5 + 10;
vector<int> G[N];
int in_degree[N];
int n, m;
vector<int> TS;
int vis[N];
void topological_sort(){
    queue<int> q;
    // priority_queue<int, vector<int>, greater<int>> q;
    // poner a una cola los de grado 0 (no tienen ninguna restriccion)
    for(int i = 0; i < n; i++)
        if(in_degree[i] == 0)
            q.push(i);

    cout << "topological_sort\n";
    while(q.size()){
        int u = q.front(); 
        cout << u << " " << q.size() << "\n";
        q.pop();
        for(int v : G[u]){
            in_degree[v]--;
            if(in_degree[v] == 0)
                q.push(v);
        }
    }
    cout << '\n';

    /*
        * para saber si hay mas de un orden topologico
        si la cola en algun momento tiene mas de un nodo, entonces
        hay mas de un orden topologico
    
        * para saber si existe orden topologico (uno/varios o ninguno)

        1ra forma.- si hay ciclo no hay TS
        2da forma.- en la cola si todos los nodos han sido procesados
                    entonces hay TS, caso contrario no hay TS

        * para obtener el Orden Topologico lexicograficamente menor
          solo usar un min heap, en vez de la cola  


    */
}

void topological_sort_recursive(int u){
    vis[u] = 1;
    for(int v : G[u])
        if(vis[v] == -1)
            topological_sort_recursive(v);

    TS.push_back(u);
}
int main (){
    // index 0
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        in_degree[v]++;
    }

    topological_sort();

    memset(vis, -1, sizeof vis);
    for(int i = 0; i < n; i++)
        if(vis[i] == -1)
            topological_sort_recursive(i);

    reverse(TS.begin(), TS.end());
    // en TS esta un orden topologico

    return 0;
}



/*
test 1 (varios TS DAG)
8 12
0 2
0 5
0 4 
1 3
1 5
1 6
3 2
5 2
5 3
5 4
6 3
7 5

test 2 (1 ts  DAG)
4 5

0 1
1 2
0 2
0 3
2 3


test 3 (not DAG)

4 6

0 1
1 2
0 2
0 3
2 3
3 1
*/
