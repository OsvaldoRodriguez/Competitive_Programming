#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int v[N];
int main()
{
  int n,ans=0,p=0;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>v[i];
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      p=0;
      for(int k=i;k<=j;k++){
        p^=v[k];
      }
      ans=max(ans,p);
    }
  }
  cout<<ans<<'\n';

  return 0;

}
