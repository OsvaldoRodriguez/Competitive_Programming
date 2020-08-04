#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int t;
  ll n,m,ans;
  cin>>t;
  while(t--){
    cin>>n>>m;
    if(n>m)
      swap(n,m);
    cout<<(n/2)*(m/2+1)+((n+1)/2)*(m-(m/2+1)+1)<<"\n";
  }
  return 0;
}
