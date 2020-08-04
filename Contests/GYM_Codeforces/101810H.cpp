#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2005;
int v[N];
int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    memset(v,0,sizeof v);
    for(int i=1;i<=2*n;i++)
      cin>>v[i];
    int ans=0;
    for(int i=1;i<=n;i++)
      ans=max(ans,v[i]+v[2*n-i+1]);
    cout<<ans<<"\n";
  }
  return 0;
}
