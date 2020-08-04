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
  ll t,n,pot,ans=0;
  cin>>t;
  while(t--){
    cin>>n;
    ans=0;
    pot=0;
    while((1LL<<pot)<=n){
      ans+=(1LL<<pot);
      pot++;
    }
    cout<<((n*(n+1))>>1)-ans-ans<<endl;

  }
  return 0;
}
