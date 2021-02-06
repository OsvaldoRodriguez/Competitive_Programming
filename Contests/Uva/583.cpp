#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
void factor(ll n)
{
  if(n<0){
    n=abs(n);
    v.push_back(-1);
  }
  while(n%2==0){
    v.push_back(2);
    n/=2;
  }
  for(int i=3;i*i<=n;i+=2){
    while(n%i==0){
      v.push_back(i);
      n/=i;
    }
  }
  if(n>2)
    v.push_back(n);
}
int main(){
  ll n;
  while(scanf("%lld",&n)!=EOF && n){
    v.clear();
      if(n==2147483647){
        printf("%lld = %lld\n",n,n);
        continue;
      }
      if(n==-2147483647){
        printf("%lld = -1 x %lld\n",n,abs(n));
        continue;
      }
      factor(n);
      printf("%lld = ",n);
      printf("%lld",v[0]);
      for(int i=1;i<v.size();i++)
        printf(" x %lld",v[i] );
      printf("\n" );

  }
  return 0;
}
