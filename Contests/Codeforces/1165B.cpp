#include <bits/stdc++.h>
using namespace std;
int v[200010];
int main()
{
  int n,x,may=0;
  int a=0,b=1100,m;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>v[i];
  int pos=1,ans=0;
  sort(v,v+n);
  int i=0;
  while(i<n)
  {
    if(v[i]>=pos)
    {
      ans++;
      pos++;
    }

    i++;
  }
  cout<<ans<<"\n";
  return 0;
}
