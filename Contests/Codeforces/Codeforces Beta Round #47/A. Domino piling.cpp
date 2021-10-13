#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1000001;

int main()
{
 
  int m,n,ans;
  while(cin>>m>>n){
    ans=0;
    ans+=n*(m/2);
    m%=2;
    if(m>0)
      ans+=m*(n/2);
    cout<<ans<<endl;
  }
 
  return 0;
}
