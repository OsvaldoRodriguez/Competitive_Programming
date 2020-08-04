#include <bits/stdc++.h>
using namespace std;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
typedef long long ll;
const int N= 201;
int v[4*N+5];
ll gcd(ll a,ll b){
  if(b==0)return a;
  return gcd(b,a%b);
}
int main(){
  int n;
  ll x,y;
  scanf("%d %I64d",&n,&x);
  n--;
  ll ans=x;
  while(n--){
    scanf("%I64d",&y);
    ans=gcd(ans,y);
  }
  //printf("%I64d\n",ans );
  ll ans1=0;
  ll i=1;
  for(;i*i<ans;i++){
    if(ans%i==0)ans1+=2;
  }
  if(i*i==ans)
  ans1++;
  printf("%I64d\n",ans1);
  return 0;
}
