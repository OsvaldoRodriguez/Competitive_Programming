#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 100005;
int dx[]={2,1,-1,-2,-2,-1,1,2},dy[]={1,2,2,1,-1,-2,-2,-1};
vector<int> G[N];
int vis[N],cont;
int cost[N];
void dfs(int u){
  vis[u]=1;
  cont=min(cont,cost[u]);
  for(int i=0;i<G[u].size();i++){
    if(!vis[G[u][i]]){
      dfs(G[u][i]);
    }
  }
}
int main(){

  int n,m,a,b;
  scanf("%d %d",&n,&m);
  ll ans=0;
  for(int i=0;i<n;i++)
    scanf("%d",&cost[i]);
  while(m--){
    scanf("%d %d",&a,&b);
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i=0;i<n;i++){
    if(!vis[i]){
      cont=1<<30;
      dfs(i);
      ans+=(ll)cont;
    }
  }
  printf("%lld\n",ans);
  return 0;
}
