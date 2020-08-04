#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 100005;
int dx[]={2,1,-1,-2,-2,-1,1,2},dy[]={1,2,2,1,-1,-2,-2,-1};
vector<int> G[N];
int est[N],cont;
bool flag=1;
void bfs(int nodo){
  est[nodo]=1;
  queue<int> q;
  q.push(nodo);
  while(!q.empty()){
    int u=q.front();q.pop();
    for(int i=0;i<G[u].size();i++){
      int v=G[u][i];
      if(est[v]==-1){
        est[v]=est[u]^1;
        q.push(v);
      }
    }
  }
}
int main(){

  int n,m,a,b;
  scanf("%d",&n);
  int cn=n;
  memset(est,-1,sizeof est);
  n--;
  while(n--){
    scanf("%d %d",&a,&b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bfs(1);
  int c1=0,c0=0;
  ll ans=0;
  for(int i=1;i<=cn;i++)
    if(est[i]==1)c1++;
    else c0++;
  for(int i=1;i<=cn;i++){
    if(est[i]==1){
      ans+=(ll)c0-(ll)G[i].size();
    }
  }
  printf("%lld\n",ans );
  return 0;
}
