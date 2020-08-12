#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 1005;
const int LOG=11;
int P[N][LOG];
int pr[N];
vector<int> G[N];
void dfs(int u,int p,int pro){
  //cout<<u<<" dfs\n";
  P[u][0]=p;
  pr[u]=pro;
  for(int i=1;i<LOG;i++)
    P[u][i]=P[P[u][i-1]][i-1];
  for(int i=0;i<G[u].size();i++){
    int v=G[u][i];
    if(v!=p)
      dfs(v,u,pro+1);
  }
}
int igualar(int u,int k){
  for(int i=0;i<LOG;i++){
    if((1<<i)&k)
      u=P[u][i];
  }
  return u;
}
int LCA(int u,int v){
  int pu=pr[u];
  int pv=pr[v];
  if(pu>pv)
    u=igualar(u,pu-pv);
  if(pv>pu)
    v=igualar(v,pv-pu);
  if(u==v)return u;
  for(int i=LOG-1;i>=0;i--){
    if(P[u][i]!=P[v][i]){
      u=P[u][i];
      v=P[v][i];
    }
  }
  return P[u][0];
}
int main(){
  int t,n,m,x,q,a,b,casos=1;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    for(int i=0;i<N;i++)
      G[i].clear();
    for(int i=0;i<n;i++){
      scanf("%d",&m);
      while(m--){
        scanf("%d",&x );
        x--;
        G[i].push_back(x);
        G[x].push_back(i);
      }
    }
    memset(P,0,sizeof P);
    memset(pr,0,sizeof pr);
    dfs(0,0,0);
    scanf("%d",&q);
    printf("Case %d:\n",casos++ );
    while(q--){
      scanf("%d %d",&a,&b);
      a--;b--;
      printf("%d\n",LCA(a,b)+1);
    }
  }
  return 0;
}
