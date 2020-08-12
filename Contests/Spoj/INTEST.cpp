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
    int n,k,ans=0,x;
    while(cin>>n>>k){
      ans=0;
      while(n--){
        cin>>x;
        if(!(x%k))
          ans++;
      }
 
      cout<<ans<<"\n";
    }
    return 0;
}
