#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N =1e5+5;
int v[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>v[i];
  sort(v,v+n);
  
  ll ans=0;
  for(int i=0;i<n-1;i+=2){
    if(v[i]<0 && v[i+1]<0){
      ans+=abs(v[i]+1)+abs(v[i+1]+1);
    }else if(v[i]<0 && v[i+1]==0){
      ans+=abs(v[i]+1)+1;
    }else if(v[i]==0 && v[i+1]==0){
      ans+=2;
    }else if(v[i]==0 && v[i+1]>0){
      ans+=abs(v[i+1]-1)+1;
    }else if(v[i]>0 && v[i+1]>0){
      ans+=abs(v[i]-1)+abs(v[i+1]-1);
    }else if(v[i]<0 && v[i+1]>0){
      ans+=abs(v[i]+1)+v[i+1]+1;
    }
  }
  if((n&1)){
    if(v[n-1]<0)
      ans+=abs(v[n-1])+1;
    if(v[n-1]==0)
      ans++;
    if(v[n-1]>0)
      ans+=v[n-1]-1;
  }
  cout<<ans<<"\n";
  return 0;
}
