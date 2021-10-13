#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 11;
int ans=0,k,n,m;
char v1[N][N][N];
int vis[N][N][N];
void dfs(int u,int v,int w){
  if(vis[u][v][w]==1) return ;
  if(v1[u][v][w]=='#'||u<0 || v<0 || w<0 || u>=k || v>=n || w>=m)
    return;
  vis[u][v][w]=1;
  ans++;
  dfs(u+1,v,w);
  dfs(u-1,v,w);
  dfs(u,v+1,w);
  dfs(u,v-1,w);
  dfs(u,v,w+1);
  dfs(u,v,w-1);
}
int main(){
  cin>>k>>n>>m;
  for(int i=0;i<k;i++)
    for(int j=0;j<n;j++)
      for(int l=0;l<m;l++)
        cin>>v1[i][j][l];
  int x,y;
  cin>>x>>y;
  x--;y--;
  dfs(0,x,y);
  cout<<ans<<"\n";
  return 0;
}
