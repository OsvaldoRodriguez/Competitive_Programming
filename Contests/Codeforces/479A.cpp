#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;

    int r=0,maxi=0;
    if(a!=1&b!=1&c!=1)
        cout<<a*b*c<<endl;
    else
    {

        r=a+b*c;
        if(maxi<r)
            maxi=r;
        r=a*(b+c);
        if(maxi<r)
            maxi=r;
        r=(a+b)*c;
        if(maxi<r)
            maxi=r;
        r=a+b+c;
         if(maxi<r)
            maxi=r;
        cout<<maxi<<endl;
    }


    return 0;
}
