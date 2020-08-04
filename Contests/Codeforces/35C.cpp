#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 2005;
//int dx[]={2,1,-1,-2,-2,-1,1,2},dy[]={1,2,2,1,-1,-2,-2,-1};
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int v[N][N],inf = 1<<30,n,m;
int dis[N][N];
void bfs(int x,int y){
  dis[x][y]=0;
  queue<int> q;
  q.push(x);q.push(y);
  while(!q.empty()){
    int a=q.front();q.pop();
    int b=q.front();q.pop();
    for(int i=0;i<4;i++){
      int a1=a+dx[i],b1=b+dy[i];
      if(a1>=0 && a1<n && b1>=0 && b1<m && dis[a][b]+1<dis[a1][b1]){
        q.push(a1);q.push(b1);dis[a1][b1]=1+dis[a][b];

      }
    }
  }
}
int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int a,b,k;
  //scanf("%d %d",&n,&m);
  cin>>n>>m;
  for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)dis[i][j]=inf;
  cin>>k;//scanf("%d",&k);
  while(k--){
    cin>>a>>b;//scanf("%d %d",&a,&b);
    a--;b--;
    bfs(a,b);
  }
  int may=-1,i1,i2;
  for(int i=0;i<n;i++)
  for(int j=0;j<m;j++){
    if(may<dis[i][j]){
      may=dis[i][j];
      i1=i;
      i2=j;
    }
  }
  cout<<i1+1<<" "<<++i2<<"\n";//printf("%d %d\n",i1+1,i2+1 );
  return 0;
}
