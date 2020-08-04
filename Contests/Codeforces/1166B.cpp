#include "bits/stdc++.h"
using namespace std;
int main()
{
  int n,pi,pj,i;
  bool sw=0;
  while(cin>>n)
  {
    sw=0;
    for(i=5;i*i<=n;i++)
      if(n%i==0)
      {
        sw=1;
        pi=i;
        pj=n/i;
        break;
      }
    string cad="aeiou";
    int pos=0;
    if(sw && (pi>=5 && pj>=5))
    {
        for(int i=0;i<pi;i++)
        {
          for(int j=0;j<pj;j++)
            cout<<cad[(pos++)%5];
          pos++;
        }
        cout<<"\n";
    }
    else
      cout<<-1<<"\n";
  }

}
