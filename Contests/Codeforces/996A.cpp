#include "bits/stdc++.h"
using namespace std;
int c[]={100,20,10,5,1};
int main()
{
  int n;
  int ans=0;
  while(cin>>n){
    ans=0;
  for(int i=0;i<5;i++)
  {
    ans+=n/c[i];
    n%=c[i];
  }
  cout<<ans<<"\n";
}
  return 0;
}
