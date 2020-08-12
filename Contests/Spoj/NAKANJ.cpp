#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 10;
int dx[]={2,1,-1,-2,-2,-1,1,2},dy[]={1,2,2,1,-1,-2,-2,-1};
int v[N][N],inf=(1<<10),dis[N][N];
void bfs(int x,int  y){
  queue<int> q;
  q.push(x);
  q.push(y);
  dis[x][y]=0;
  while(!q.empty()){
    int a=q.front();q.pop();
    int b=q.front();q.pop();
    for(int i=0;i<8;i++){
      int a1=a+dx[i],b1=b+dy[i];
      if(a1>=1 && a1<=8 && b1>=1 && b1<=8 && dis[a][b]+1<dis[a1][b1]){
        dis[a1][b1]=1+dis[a][b];
        q.push(a1);q.push(b1);
      }
    }
  }
}
 
int main(){
  int t,x1,y1,x2,y2;
  scanf("%d",&t);
  char s[10];
  while(t--){
    for(int i=1;i<=8;i++)
      for(int j=1;j<=8;j++) dis[i][j]=inf;
    scanf("%s",&s);
    x1=s[0]-'a'+1;y1=s[1]-'0';
    scanf("%s",&s);
    bfs(x1,y1);
    x2=s[0]-'a'+1;y2=s[1]-'0';
    printf("%d\n",dis[x2][y2]);
  }
  return 0;
}
