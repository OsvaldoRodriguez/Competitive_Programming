#include <bits/stdc++.h>
using namespace std;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
typedef long long ll;
const int N= 2*1e5+5;
ll v[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  ll k;
  cin>>n>>k;
  for(int i=0;i<n;i++)
    cin>>v[i];
  sort(v,v+n);
  ll ans=v[n/2];
  ll cmp=1;
  for(int i=n/2+1;i<n;i++){
    if((v[i]-v[i-1])*cmp<=k){
      ans+=(v[i]-v[i-1]);
      //cout<<ans<<endl;
      k-=(v[i]-v[i-1])*cmp;
      cmp++;
    }else{
      ans+=(k/cmp);
      k=0;
      break;
    }
  }
  //cout<<k<<" "<<cmp<<endl;
  if(k>0)
  ans+=(k/cmp);
  cout<<ans<<"\n";
  return 0;
}
