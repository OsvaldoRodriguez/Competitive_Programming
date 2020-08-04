#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
int fre[N],vis[N];
int main(){
  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
  int t,n,x;
  cin>>t;
  while(t--){
    cin>>n;
    memset(vis,0,sizeof vis);
    memset(fre,0,sizeof fre);
    for(int i=0;i<n;i++){
      cin>>x;
      fre[x]++;
    }
    ll ans=0;
    for(int i=1;i<N;i++){
      if(fre[i]){
        for(int j=i;j<N;j+=i){
          if(fre[j] && !vis[j]){
            ans+= (ll)fre[j]*(ll)i;vis[j]=1;
          }
        }
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
