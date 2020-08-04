#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =1005;
int v[N];
ll f(ll n){
  return n*(n-1)>>1;
}
int main(){
  ll n,m,mini,may;
  while(cin>>n>>m){
    mini=f(n/m+1)*(n%m)+f(n/m)*(m-n%m);
    may=f(n-m+1);
    cout<<mini<<" "<<may<<"\n";
  }
  return 0;
}
