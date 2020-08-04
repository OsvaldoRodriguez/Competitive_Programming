#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,nn,sum;
  cin>>n;
  int ans;
  while(1){
    nn=n;
    sum=0;
    while(nn>0)
    {
      sum+=nn%10;
      nn/=10;
    }
    if(sum%4==0)
    {
      ans=n;
      break;
    }
    n++;
  }
  cout<<ans<<'\n';

  return 0;
}
