#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N =21;
int main()
{
  ll n;
  cin>>n;
  ll v[n];
  for(auto i=0;i<n;i++)
    cin>>v[i];
  ll ans=0,s;
  for(int i=0;i<(1<<n);i++){
    s=0;
    for(int j=0;j<n;j++){
      if(i&(1<<j)){
        s|=v[j];
      }
    }
    ans+=s;
  }
  cout<<ans<<endl;
  return 0;
}
