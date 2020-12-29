#include <bits/stdc++.h>
using namespace std;
int v[26][26],vis[26][26];
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
int n;
void dfs(int a,int b)
{
  vis[a][b]=1;
  for(int i=0;i<8;i++){
    int a1=a+dx[i],b1=b+dy[i];
    if(a1>=0 && a1<n && b1>=0 && b1<n && !vis[a1][b1] && v[a1][b1])
      dfs(a1,b1);
  }
}
int main()
{
  int ans,test=1;
  char s;
  while(cin>>n)
  {
    ans=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin>>s;
        if(s=='0')
          v[i][j]=0;
        else
          v[i][j]=1;
        vis[i][j]=0;
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(!vis[i][j] && v[i][j]){
          ans++;dfs(i,j);
        }
      }
    }
    printf("Image number %d contains %d war eagles.\n",test++,ans );
  }

  return 0;
}
