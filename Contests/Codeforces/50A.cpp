#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1000001;
int GCD(int a,int b){
  if(!b)return a;
  return GCD(b,a%b);
}
int LCM(int a,int b){
  return a*(b/GCD(a,b));
}
bool potencia(ll x){
  if((x&(x-1))==0)
    return 1;
  return 0;
}
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
