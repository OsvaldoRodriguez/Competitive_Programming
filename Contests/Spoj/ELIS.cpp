#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=11;
int dp[N],v[N];
int f(int i){
  if(dp[i]!=-1)
    return dp[i];
  int sol=1;
  for(int j=0;j<i;j++){
    if(v[j]<v[i]){
      sol=max(sol,1+f(j));
    }
  }
  return dp[i]=sol;
}
int main()
{
  int n;
  cin>>n;
  memset(dp,-1,sizeof dp);
  for(int i=0;i<n;i++)
    cin>>v[i];
  int ans=0;
  for(int i=0;i<n;i++)
    ans=max(ans,f(i));
  cout<<ans<<endl;
  return 0;
}
