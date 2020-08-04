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
    int n;
    string s;
    int a=0,b=0;
    cin>>n>>s;
    bool flag=1;
    for(int i=0;i<n/2;i++){
      if(s[i]=='4' or s[i]=='7')
      a+=s[i]-'0';
      else{

        flag=0;break;
      }
      if(s[i+n/2]=='4' or s[i+n/2]=='7')
      b+=s[i+n/2]-'0';
      else
      {
        flag=0;break;
      }
    }
    if(a==b && flag)
      cout<<"YES\n";
    else
      cout<<"NO\n";
    return 0;
}
