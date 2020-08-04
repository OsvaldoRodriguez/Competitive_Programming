#include <bits/stdc++.h>
using namespace std;
int dis[10005];
void bfs(int n,int m){
  dis[n]=0;
  queue<int> q;
  q.push(n);
  while(!q.empty()){
    int u=q.front();q.pop();
    if(u==m){
      cout<<dis[u]<<"\n";
      return ;
    }
    int a=u*2;
    if(a<10005 && dis[a]==-1){
      dis[a]=dis[u]+1;
      q.push(a);
    }
    int b=u-1;
    if(b>0 && dis[b]==-1){
      dis[b]=dis[u]+1;
      q.push(b);
    }
  }
}
int main(){
  int n,m;
  while(cin>>n>>m){
    memset(dis,-1,sizeof dis);
    bfs(n,m);
  }
  return 0;
}
