#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a ,ll b){
  if(b==0)return a;
  return gcd(b,a%b);
}
int main(){
  int t,n;
  ll x,ans,ans1;
  scanf("%d",&t);
  while(t--){
    ans=0;
    scanf("%d %lld",&n,&x);
    n--;
    ans=x;
    ans1=x;
    for(int i=0;i<n;i++){
      scanf("%lld",&x);
      ans+=x;
      ans1=gcd(ans1,x);
    }
    printf("%lld %d\n",ans,ans1);
  }
  return 0;
}
