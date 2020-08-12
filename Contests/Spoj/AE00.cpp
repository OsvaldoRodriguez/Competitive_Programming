#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 10010;
int dp[N];
int f(int n){
  int ans=0;
  for(int i=1;i*i<=n;i++)
    if(n%i==0)
      ans++;
  return ans;
}
int main()
{
  int n;
  while(cin>>n){
    int ans=0;
    for(int i=1;i<=n;i++)
      ans+=f(i);
      cout<<ans<<endl;
  }
 
 
 
  return 0;
}
