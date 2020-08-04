#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =100005;
int main(){
  ll n,m,x,y,ans;
  cin>>n>>m>>x;
  m--;
  ans=x-1;
  while(m--){
    cin>>y;
    if(x==y)
      continue;
    if(y<x)
      ans+=n-x+y;
    else
      ans+=y-x;
    x=y;
  }
  cout<<ans<<endl;
  return 0;
}
