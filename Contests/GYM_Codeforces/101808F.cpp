#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N= 1005;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
int v[N],f[N],mod=7901;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll r1,r2;
  f[0]=1;
  for(int i=1;i<N;i++)
    f[i]=(f[i-1]%mod*i%mod)%mod;
  int t,n,x;
  cin>>t;
  int ans;
  while(t--){
    ans=1;
    memset(v,0,sizeof v);
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>x;
      v[x]++;
    }
    for(int i=0;i<N;i++){
      if(v[i])
        ans=(ans%mod*f[v[i]]%mod)%mod;
    }
    cout<<ans<<"\n";
  }
  return 0;
}
