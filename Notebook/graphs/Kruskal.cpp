#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
const int N = 1e5 + 50;
vector<tuple<int, int, int>> G; // (w, u, v)
int P[N], rnk[N];
int n, m;
/*
n vetex
m edges
Complexity
Time:
    kruskal -> O(m log n)
*/
int FIND(int u){return u == P[u] ? u : FIND(P[u]);}
void init(){
    for(int i = 0; i < n; i++){
        P[i] = i;
        rnk[i] = 0;
    }
}
int kruskal(){
    init(); // disjoint set union
    ll ans = 0;
    sort(G.begin(), G.end());
    for(int i = 0; i < m; i++){
        int w, u, v;
        tie(w, u, v) = G[i];
        int pu = FIND(u);
        int pv = FIND(v);
        if(pu != pv){
            if(rnk[pu] < rnk[pv])
                swap(pu, pv);
            P[pv] = pu;
            if(rnk[pu] == rnk[pv])
                rnk[pu]++;
            ans += w;
        }
    }
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G.push_back({w, u, v});
    }
    cout << kruskal() << '\n';
    return 0;
}       
