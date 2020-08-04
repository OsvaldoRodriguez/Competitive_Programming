#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> G[101];
int vis[101];
void dfs(int u){
  vis[u]=1;
  for(int i=0;i<G[u].size();i++){
    int v=G[u][i];
    if(vis[v]==-1){
      dfs(v);
    }

  }
}
int main()
{
  bool flag=1;
  int n,m,a,b,cm;
  cin>>n>>m;
  memset(vis,-1,sizeof vis);
  for(int i=0;i<=n;i++)
    G[i].clear();
    cm=m;
  while(m--){
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1);
  for(int i=1;i<=n;i++)
    if(vis[i]==-1){
      flag=0;
      break;
    }
  if(flag && n==cm)
    cout<<"FHTAGN!\n";
  else
    cout<<"NO\n";
  return 0;
}
