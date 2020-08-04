#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 100001;
// 2 4
int main()
{
  ll a,b,ans;
  while(cin>>a>>b){
    ans=1;
    for(ll i=b;i>a;i--){
      ans=(ans%10*i%10)%10;
      if(!ans)break;
    }

    cout<<ans<<endl;
  }
  return 0;
}
