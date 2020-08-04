#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll POW(ll a,ll b,ll m)
{
  if(!b)return 1;
  if(!(b&1))
    return POW((a%m*a%m)%m,b/2,m);
  return (POW((a%m*a%m)%m,b/2,m)*a%m)%m;
}
int main()
{
    long long n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
      sum+=POW(2,i,(1LL<<60));
    cout<<sum<<endl;
    return 0;
}
