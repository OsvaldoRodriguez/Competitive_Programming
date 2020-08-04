#include "bits/stdc++.h"
using namespace std;
int n,s;
void f()
{
  if((n==1 and s>9) || (s==0 and n>1))
  {
    cout<<"-1 -1\n";
    return ;
  }
  if(n==1 and  s<10)
  {
    cout<<s<<" "<<s<<"\n";
    return ;
  }
  string max="";
  int s1=s;
  for(int i=0;i<n;i++)
  {
    if(s1>=9)
    {
      max+="9";
      s1-=9;
    }
    else
    {
        max+=(char)(s1+'0');
        s1-=s1;
    }
  }
  if(s1!=0)
  {
    cout<<"-1 -1\n";
    return ;
  }
  string min=max;
  reverse(min.begin(),min.end());
  if(min[0]=='0')
  {
    min[0]='1';
    for(int i=1;i<n;i++)
    {
      if(min[i]!='0')
      {
        min[i]=char(min[i]-1);
        break;
      }

    }
  }
  cout<<min<<" "<<max<<"\n";
  return;
}
int main()
{
  while(cin>>n>>s)
  f();
}
