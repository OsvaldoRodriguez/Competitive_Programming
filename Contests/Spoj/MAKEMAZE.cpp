#include <bits/stdc++.h>
using namespace std;
int n,m,dx[]={1,0,-1,0},dy[]={0,1,0,-1},vis[25][25] ;
int vv[25][25];
vector<int> v;
void dfs(int x,int y){
  vis[x][y]=1;
  for(int i=0;i<4;i++){
    int a1=x+dx[i],b1=y+dy[i];
    if(a1>=1 && a1<=n && b1>=1 && b1<=m && !vis[a1][b1] && vv[a1][b1])
      dfs(a1,b1);
  }
}
void bfs(int x,int y){
  vis[x][y]=1;
  queue<int> q;
  q.push(x);q.push(y);
  while(!q.empty()){
    int a=q.front();q.pop();
    int b=q.front();q.pop();
    for(int i=0;i<4;i++){
      int a1=a+dx[i],b1=b+dy[i];
      if(a1>=1 && a1<=n && b1>=1 && b1<=m && !vis[a1][b1] && vv[a1][b1]){
        q.push(a1);
        q.push(b1);
        vis[a1][b1]=1;
      }
    }
  }
}
int main(){
  int test;
  char s;
  cin>>test;
  while(test--){
    memset(vv,0,sizeof vv);
    v.clear();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        cin>>s;
        if(s=='.')
          vv[i][j]=1;
        if((i==1 || i==n || j==1 || j==m) && vv[i][j]){
          //cout<<i<<' '<<j<<" ops\n";
          v.push_back(i);v.push_back(j);
        }
        vis[i][j]=0;
      }
    }
    /*for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++)
        cout<<vv[i][j];
      cout<<endl;
    }
    //cout<<v.size()<<" tam\n";*/
    if(v.size()==4)
    {
      dfs(v[0],v[1]);
      if(vis[v[2]][v[3]])
        cout<<"valid\n";
      else
        cout<<"invalid\n";
    }
    else
      cout<<"invalid\n";
 
 
 
  }
  return 0;
}
