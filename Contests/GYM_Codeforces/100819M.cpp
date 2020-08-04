#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 101;
int v[N];
int vis[N];
int main(){
  int n,x;
  string s;
  cin>>n;
  for(int i=1;i<=100;i++)
    v[i]=i;
  while(n--){
    cin>>s>>x;
    if(s=="ADD")
      for(int i=1;i<=100;i++){
        if(v[i]<0)
          vis[i]=1;
        v[i]+=x;
      }
    if(s=="SUBTRACT")
      for(int i=1;i<=100;i++){
        v[i]-=x;
        if(v[i]<0)
          vis[i]=1;
      }

    if(s=="MULTIPLY")
      for(int i=1;i<=100;i++){
        if(v[i]<0)
          vis[i]=1;
        v[i]*=x;
      }
    if(s=="DIVIDE")
      for(int i=1;i<=100;i++){
        if(v[i]%x!=0)
          vis[i]=1;
        else
          v[i]/=x;
      }
  }
  int ans=0;
  for(int i=1;i<=100;i++){
    if(vis[i])
      ans++;
    //cout<<v[i]<<" "<<vis[i]<<"\n";
  }
  //cout<<endl;
  cout<<ans<<endl;
  return 0;
}
