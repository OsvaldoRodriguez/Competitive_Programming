#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  double v[n+1];
  int c[n+1];
  int s=0;
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
    c[i]=floor(v[i]);
    s+=c[i];
  }
  for(int i=0;i<n && s<0;i++)
      if(v[i]!=c[i])
          c[i]++,s++;
    for(int i=0;i<n;i++)  cout<<c[i]<<"\n";
}
