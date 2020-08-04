#include "bits/stdc++.h"
using namespace std;
int main()
{
  int n,s=0;
  cin>>n;
  int v[n];
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
    s+=v[i];
  }
  sort(v,v+n);
  int pr=0;
  int i=0;
  double p=double(s)/double(n);
  while(p<4.5000000000)
  {
    s+=5-v[i++];
    p=double(s)/double(n);
  }
  cout<<i<<"\n";
  return 0;
}
