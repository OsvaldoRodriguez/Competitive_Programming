#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> il;
typedef pair<ll,int> li;
const int N = 5009;
vector<il> G[N],Ginv[N];
ll dn[N],dc[N],inf=(1LL<<60);
bool vis[N];
int dis[N];
vector<int> vec;
void dijkstra(int nodo,ll *dis){
  dis[nodo]=0;
  set<li> s;
  s.insert(li(0,nodo));
  while(!s.empty()){
    li top=*s.begin();
    s.erase(s.begin());
    int u=top.second;
    int d=top.first;
    if(d>dis[u])continue;
    for(int i=0;i<G[u].size();i++){
      int v=G[u][i].first;
      ll cost=G[u][i].second;
      if(dis[u]+cost<dis[v]){
        dis[v]=cost+dis[u];
        s.insert(li(dis[v],v));
      }
    }
  }
}
void dfs(int u){
  vis[u]=1;
  //cout<<" dfs "<<u<<endl;
  for(int i = 0; i <G[u].size(); i++){
    int v=G[u][i].first;
    ll cost=G[u][i].second;
    //if(!vis[v]){
      if(!vis[v] && dn[u]-cost==dn[v] && dc[u]-cost==dc[v]){
        //cout<<u<<" nodo comun "<<v<<"\n";
        Ginv[v].push_back(il(u,cost));
        dfs(v);
      }
    //}
  }
  vec.push_back(u);
}
void dfs1(int u){
  for(int i=0;i<Ginv[u].size();i++){
    il v=Ginv[u][i];
    if(dis[u]+v.second>dis[v.first])
      dis[v.first]=dis[u]+v.second;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m,b,c,nn,u,v;
  ll cost;
  while(cin>>n>>b>>c>>nn>>m){
    vec.clear();
    if(m==-1 && n==-1 && b==-1 &&nn==-1 && c==-1)
      break;
    for(int i=0;i<=n;i++){
      dc[i]=dn[i]=inf;
      G[i].clear();
      vis[i]=0;
      Ginv[i].clear();
      dis[i]=0;
    }
    while(m--){
      cin>>u>>v>>cost;
      G[u].push_back(il(v,cost));
      G[v].push_back(il(u,cost));
    }
    dijkstra(c,dc);
    //cout<<dc[b]<<" charlie\n";
    dijkstra(nn,dn);
    //cout<<dn[b]<<" nito\n";
    //cout<<"buscando cumun\n";
    dfs(b);
    //cout<<" topso\n";
    //for(int i=0;i<vec.size();i++)
      //cout<<vec[i]<<" ";
    //cout<<endl;
    for(int i=0;i<vec.size();i++){
      dfs1(vec[i]);
    }
    //cout<<" distancia en comun\n";
    cout<<dis[b]<<" "<<dc[b]-dis[b]<<" "<<dn[b]-dis[b]<<"\n";
  }
  return 0;
}
