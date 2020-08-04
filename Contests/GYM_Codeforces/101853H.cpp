#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 1e5+5;
int main(){
  int t;
  ll x;
  scanf("%d",&t );
  while(t--){
    scanf("%lld",&x);
    ll i=1;
    for(;i*i<x;i++){
      if(x%i==0){
        if(i*i*6==x){
          printf("%lld\n",i);
          break;
        }
      }
    }
  }
  return 0;
}

