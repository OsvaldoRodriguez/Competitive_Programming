#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> G[1001];
vector<int> sol;
int vis[1001];
void bfs(int nodo){
  queue<int> q;
  vis[nodo]=1;
  q.push(nodo);
  while(!q.empty()){
    int u=q.front();q.pop();
    sol.push_back(u);
    for(int i=0;i<G[u].size();i++){
      int v=G[u][i];
      if(vis[v]==-1){
        q.push(v);
        vis[v]=1;
      }
    }
  }
}
void dfs(int u){
  vis[u]=1;
  sol.push_back(u);
  for(int i=0;i<G[u].size();i++){
    int v=G[u][i];
    if(vis[v]==-1){
      dfs(v);
    }
  }
}
int main()
{
  int t,n,j,m,a,b,test=1;
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<=n;i++)
      G[i].clear();
    while(n--){
      cin>>j>>m;
      while(m--){
        cin>>a;
        G[j].push_back(a);
      }
    }
    cout<<"graph "<<test++<<"\n";
    while(cin>>a>>b){
      if(a==b && b==0)
        break;
      sol.clear();
      memset(vis,-1,sizeof vis);
      if(b==0){
        dfs(a);
      }
      else{
        bfs(a);
      }
      //sort(sol.begin(),sol.end());
      for(int k=0;k<sol.size();k++)
        cout<<sol[k]<<" ";
        cout<<"\n";
    }
  }
 
}
