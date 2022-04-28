#include <bits/stdc++.h>
using namespace std;
int n,m;
int v[101][101],vis[101][101];
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
void dfs(int a,int b)
{
  vis[a][b]=1;
  for(int i=0;i<8;i++)
  {
    int a1=a+dx[i],b1=b+dy[i];
    if(a1<n && a1>=0 && b1<m && b1>=0 && !vis[a1][b1] && v[a1][b1])
      dfs(a1,b1);
  }

}
int main()
{
  char s;
  int ans;
  while(cin>>n>>m && n && m)
  {
    memset(v,0,sizeof v);
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>s;
        if(s=='*')
          v[i][j]=0;
        else
          v[i][j]=1;
        vis[i][j]=0;
      }
    }
    ans=0;
    for(int i =0;i<n;i++){
      for(int j=0;j<m;j++){
        if(!vis[i][j] && v[i][j])
        {
          ans++;
          dfs(i,j);
        }
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}
