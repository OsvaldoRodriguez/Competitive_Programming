#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int v[N];
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>v[i];
  sort(v,v+n);
  int ans=(1<<30);
  for(int i=0;i<n;i++)
    ans=min(ans,v[i]+v[n-i-1]);
  cout<<ans<<"\n";
  return 0;
}
