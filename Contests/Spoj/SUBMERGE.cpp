#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =10005;
int ans,t;
vector<int> G[N];
int T[N],L[N],P[N],puntos[N];
void dfs(int u){
  int children=0;
  T[u]=L[u]=t++;
  for(int i=0;i<G[u].size();i++){
    int v=G[u][i];
    if(!T[v]){
      children++;
      P[v]=u;
      dfs(v);
      L[u]=min(L[u],L[v]);
      if(P[u]==-1 && children>1)
        puntos[u]=1;
      if(L[v]>=T[u] && P[u]!=-1)
        puntos[u]=1;
    }else if(P[u]!=v)
      L[u]=min(L[u],T[v]);
  }
}
int main(){
  int n,m,a,b;
  while(cin>>n>>m && n && m){
    ans=0;t=1;
    for(int i=0;i<=n;i++)
      T[i]=L[i]=0,P[i]=-1,puntos[i]=0;
    for(int i=1;i<=n;i++)
      G[i].clear();
      for(int i=0;i<m;i++){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
      }
    for(int i=1;i<=n;i++)
      if(!T[i])
        dfs(i);
    ans=0;
    for(int i=1;i<=n;i++)
      if(puntos[i])
        ans++;
    cout<<ans<<endl;
  }
  return 0;
}
