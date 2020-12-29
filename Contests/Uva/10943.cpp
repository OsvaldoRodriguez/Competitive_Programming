#include <bits/stdc++.h>
using namespace std;
#define N 101
#define m 1000000
int dp[N][N];
int sol(int n,int k)
{
  if(k==1)
    return dp[n][k]=1;
  if(dp[n][k]!=-1)
    return dp[n][k];
  int ans=0;
  for(int i=0;i<=n;i++){
    ans=(ans%m+sol(i,k-1)%m)%m;
  }
  return dp[n][k]=ans;
}
int main() {

  int n,k;
  while(scanf("%d %d",&n,&k )!=EOF && n && k)
  {
    memset(dp,-1,sizeof dp);
    printf("%d\n",sol(n,k));

  }
  return 0;
}
