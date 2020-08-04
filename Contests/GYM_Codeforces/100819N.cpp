#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int v[N];
int main(){
  int n,k,x;
  string s;
  int rompe,norompe=1;
  cin>>n>>k;
  rompe=k;
  while(n--){
    cin>>x>>s;
    if(s=="SAFE")
      norompe=max(norompe,x);
    if(s=="BROKEN")
      rompe=min(rompe,x);
  }
  cout<<norompe+1<<" "<<rompe-1<<"\n";

  return 0;
}
