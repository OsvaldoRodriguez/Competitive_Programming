#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 20005;
int v[N];
int main()
{
  int t,n,k;
  cin>>t;
  while(t--){
    cin>>n>>k;
    for(int i=0;i<n;i++)
      cin>>v[i];
    sort(v,v+n);
    int ans=(1<<30),r;
    for(int i=0;i<n-k+1;i++){
      ans=min(v[i+k-1]-v[i],ans);
    }
    cout<<ans<<endl;
  }
  return 0;
}
