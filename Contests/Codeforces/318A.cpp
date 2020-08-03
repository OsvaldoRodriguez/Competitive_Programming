#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;

    if(m<=n)
    {
      if(n%2==0)
      {
          if(m<=n/2)
            cout<<m+(m-1)<<endl;
          else
            cout<<(m-(n/2))*2<<endl;
      }
      else
      {
          if(m<=n/2+1)
            cout<<m+(m-1)<<endl;
          else
            cout<<(m-(n/2+1))*2<<endl;
      }
    }


    return 0;
}
