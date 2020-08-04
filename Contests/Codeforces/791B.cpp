#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 150001;
vector<int> G[N];
ll edges,vertex;
int vis[N];
void dfs(int u){
  vis[u]=1;
  vertex++;
  edges+=G[u].size();
  for(int i=0;i<G[u].size();i++){
    int v=G[u][i];
    if(vis[v]==-1){
      dfs(v);
    }
  }
}
int main()
{
  int n,m,a,b;
  cin>>n>>m;
  while(m--){
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  memset(vis,-1,sizeof vis);
  for(int i=1;i<=n;i++){
    if(vis[i]==-1){
      edges=0,vertex=0;
      dfs(i);
      //cout<<vertex<<" arcos "<<edges<<endl;
      if(edges!=vertex*(vertex-1)){
        cout<<"NO\n";return 0;
      }
    }
  }
  cout<<"YES\n";
  return 0;
}
