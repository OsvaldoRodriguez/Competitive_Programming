#include <bits/stdc++.h>
using namespace std;
bool flag;
int vis[210];
vector<int> G[210];
void bfs(int nodo)
{
  queue<int> q;
  vis[nodo]=0;//puede estar en 0 o en 1 da lo mismo
  q.push(nodo);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for(int i=0;i<G[u].size();i++){
      int v=G[u][i];
      if(vis[v]==-1){
        q.push(v);
        vis[v]=vis[u]^1;
      }
      else if(vis[u]==vis[v])
        flag=0;
    }
  }

}
int main()
{
  int n,m,a,b;
  while(cin>>n && n)
  {
    flag=1;
    cin>>m;
    for(int i=0;i<n;i++)
      G[i].clear();
    for(int i=0;i<m;i++)
    {
      cin>>a>>b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    memset(vis,-1,sizeof vis);
    bfs(0);
    if(flag)
      cout<<"BICOLORABLE.\n";
    else
      cout<<"NOT BICOLORABLE.\n";

  }

  return 0;
}
