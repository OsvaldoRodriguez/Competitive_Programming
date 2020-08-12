#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
const int N = 20005;
int main()
{
  int t;
  cin>>t;
  ll a,ans;
  string s,s1;
  while(t--){
    cin>>a>>s1;
    ans=a;
    while(1){
      cin>>a>>s;
        if(s1=="+")
          ans+=a;
        if(s1=="*")
          ans*=a;
        if(s1=="/")
          ans/=a;
        if(s1=="-")
          ans-=a;
 
      s1=s;
      if(s=="=")
        break;
    }
    cout<<ans<<endl;
  }
  return 0;
}
