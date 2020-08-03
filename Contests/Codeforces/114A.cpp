#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long k,l,sum=1,cont=0;
    cin>>k>>l;
    bool sw=false, bol=true;
   while(sum<=l)
   {

       sum*=k;
       cont++;
       if(sum==l)
       {
           sw=true;
           break;
       }

   }

   if(sw)
    cout<<"YES\n"<<cont-1<<endl;
   else
    cout<<"NO"<<endl;
    return 0;
}
