#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> G[N];
int scc[N], num[N], low[N], nscc = 1;
int ts = 1;
bool isPila[N];
stack<int> s;
void tarjan(int u){
    num[u] = low[u] = ts;
    ts++;
    s.push(u);
    isPila[u] = true;
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(num[v] == -1){
            tarjan(v);
        }
        if(isPila[v]){
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == num[u]){
        int v;
        do{
            v = s.top(); s.pop(); isPila[v] = 0;
            scc[v] = nscc;
        } while (v != u);
        nscc++;
    }
}

int main(){
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        G[i].clear();
    while(m--){
        scanf("%d %d",&a, &b);
        G[a].push_back(b);
    }
    memset(num, -1, sizeof num);
    for(int i = 0; i < n; i++)
        if(num[i] == -1){
            ts = 1;
            tarjan(i);
        }
    for(int i = 0; i < n; i++)
        cout << i << " comp " << scc[i] << "\n"; 
    return 0;
}
