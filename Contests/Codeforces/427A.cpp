#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,ans=0,t=0,x;
  scanf("%d",&n );
  while(n--)
  {
    cin>>x;
    if(x==-1)
    {
      if(t>0)
        t-=1;
      else
        ans+=1;
    }
    else
      t+=x;
  }
  printf("%d\n",ans );

  return 0;

}
