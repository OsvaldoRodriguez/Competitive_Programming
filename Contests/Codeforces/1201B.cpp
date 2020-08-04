#include <bits/stdc++.h>
using namespace std;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
typedef long long ll;
const int N= 100005;
ll v[N];
map<ll,ll> m;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;
  ll ans=0,x;
  ll may=0;
  for(int i=0;i<n;i++){
    cin>>v[i];
    ans+=v[i];
    m[v[i]]++;
    if(may<v[i])
      may=v[i];
  }
  if(n==2){
    if(v[0]==v[1])cout<<"YES\n";
  else cout<<"NO\n";
  return 0;
}

  if((ans&1))cout<<"NO\n";
  else{
    //cout<<ans<<"\n";
    ans-=may;
    //cout<<ans<< " restar \n";
    if(ans>=may)
      cout<<"YES\n";
      else cout<<"NO\n";
  }
  return 0;
}
