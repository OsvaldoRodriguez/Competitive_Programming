#include <bits/stdc++.h>
using namespace std;
int test,n,m,s,t;
typedef long long ll;
typedef pair<int,ll> il;
typedef pair<ll,int> li;
vector<il> G[20002];
ll dis[20002];
void Dijkstra(int nodo){
  for(int i=0;i<20002;i++)
    dis[i]=(1LL<<60);
  set<li> q;
  dis[nodo]=0;
  q.insert(li(0,nodo));
  while(!q.empty()){
    li top=*q.begin();
    q.erase(q.begin());
    int u=top.second;
    for(int i=0;i<G[u].size();i++){
      int v=G[u][i].first;
      ll cost=G[u][i].second;
      if(dis[v]>dis[u]+cost){
        dis[v]=dis[u]+cost;
        q.insert(li(dis[v],v));
      }
    }
  }

}
int main(){
  int u,vv,cases=1;
  ll w;
  cin>>test;
  while(test--)
  {
    for(int i=0;i<n;i++)
      G[i].clear();
    cin>>n>>m>>s>>t;
    while(m--){
      cin>>u>>vv>>w;
      G[u].push_back(il(vv,w));
      G[vv].push_back(il(u,w));
    }
    Dijkstra(s);
    cout<<"Case #"<<cases++<<": ";
    if(dis[t]==(1LL<<60))
      cout<<"unreachable\n";
    else
      cout<<dis[t]<<'\n';

  }
  return 0;
}
