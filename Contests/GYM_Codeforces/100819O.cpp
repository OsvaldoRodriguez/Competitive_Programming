#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 501;
char v[N][N];
int dis[N][N],inf=(1<<30),n,m;
void bfs(int x,int y){
  dis[x][y]=0;
  queue<int> q;
  q.push(x);q.push(y);
  while(!q.empty()){
    int a=q.front();q.pop();
    int b=q.front();q.pop();
    int a1=a+(v[a][b]-'0'),b1=b;
    if(a1>=0 && a1<n && b1>=0 && b1<m && dis[a][b]+1<dis[a1][b1]){
      dis[a1][b1]=1+dis[a][b];
      q.push(a1);
      q.push(b1);
    }

    b1=b+(v[a][b]-'0'),a1=a;
    if(a1>=0 && a1<n && b1>=0 && b1<m && dis[a][b]+1<dis[a1][b1]){
      dis[a1][b1]=1+dis[a][b];
      q.push(a1);
      q.push(b1);
    }

    a1=a-(v[a][b]-'0'),b1=b;
    if(a1>=0 && a1<n && b1>=0 && b1<m && dis[a][b]+1<dis[a1][b1]){
      dis[a1][b1]=1+dis[a][b];
      q.push(a1);
      q.push(b1);
    }

    b1=b-(v[a][b]-'0'),a1=a;
    if(a1>=0 && a1<n && b1>=0 && b1<m && dis[a][b]+1<dis[a1][b1]){
      dis[a1][b1]=1+dis[a][b];
      q.push(a1);
      q.push(b1);
    }
  }
}
int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>v[i][j];
      dis[i][j]=inf;
    }
  }
  bfs(0,0);
  int ans=dis[n-1][m-1];
  if(ans==inf)
    cout<<"IMPOSSIBLE\n";
  else
    cout<<ans<<"\n";
  return 0;
}
