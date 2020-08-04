#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 10010;
map<string,int> m;
vector<int> G[300];
int vis[300],r;
void dfs(int u){
  vis[u]=1;
  for(int i=0;i<G[u].size();i++){
    int v=G[u][i];
    if(vis[v]==-1){
      r++;
      dfs(v);
    }
  }
}
int main()
{
  int n,conj=1;
  cin>>n;
  string a,b,c;
  while(n--){
    cin>>a>>b>>c;
    for(int i=0;i<a.size();i++)
      a[i]=tolower(a[i]);
      for(int i=0;i<c.size();i++)
        c[i]=tolower(c[i]);
    if(m[a]==0)
      m[a]=conj++;
    if(m[c]==0)
      m[c]=conj++;
    G[m[a]].push_back(m[c]);
  }
  int ans=0;
  for(int i=0;i<conj;i++){
    r=0;
    memset(vis,-1,sizeof vis);
    dfs(i);
    ans=max(r,ans);
  }
  cout<<ans+ 1<<endl;
  return 0;
}
