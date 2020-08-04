#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 3001;
ll s[N],c[N],dp[N];
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>s[i];
  for(int i=0;i<n;i++)
    cin>>c[i];
  for(int i=0;i<n;i++)
  {
    dp[i]=(1LL<<60);
    for(int j=i+1;j<n;j++)
    {
      if(s[j]>s[i])
        dp[i]=min(dp[i],c[j]);
    }
    if(dp[i]==(1LL<<60))
      dp[i]=-1;
  }
  ll ans=(1LL<<60);
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(s[j]>s[i])
      {
        if(dp[j]!=-1)
          ans=min(ans,c[i]+c[j]+dp[j]);
      }
    }
  }
  if(ans==(1LL<<60))
    cout<<"-1\n";
  else
    cout<<ans<<'\n';
  return 0;
}
