#include <bits/stdc++.h>
using namespace std;
int v[185][185],dis[185][185],n,m,dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int inf=(1<<30);
void bfs(int x,int y){
  queue<int> q;
  q.push(x);
  q.push(y);
  while(!q.empty()){
    int a=q.front();q.pop();
    int b=q.front();q.pop();
    for(int i=0;i<4;i++){
      int a1=a+dx[i],b1=b+dy[i];
      if(a1>=0 && a1<n && b1>=0 && b1<m && dis[a][b]+1<dis[a1][b1]){
        q.push(a1);
        q.push(b1);
        dis[a1][b1]=dis[a][b]+1;
      }
    }
  }
}
int main()
{
  int t;
  char s;
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    memset(v,0,sizeof v);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
        cin>>s;
        if(s=='1')
          v[i][j]=1;
        if(v[i][j]==1)
          dis[i][j]=0;
        else
          dis[i][j]=inf;
      }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(v[i][j]==1)
          bfs(i,j);
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++)
        cout<<dis[i][j]<<' ';
      cout<<"\n";
    }
 
  }
  return 0;
}
