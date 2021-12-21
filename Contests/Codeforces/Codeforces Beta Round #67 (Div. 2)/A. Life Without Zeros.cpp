#include <bits/stdc++.h>

using namespace std;
long long darVuelta(long long x)
{   long long xx=0,dig1=0;
    while(x!=0)
    {
        long long dig1=x%10;
            xx=xx*10+dig1;
            x/=10;
    }
    return xx;
}

long long quitarZeros(long long x)
{
   long long xx=0,dig1=0;
    while(x!=0)
    {
        long long dig1=x%10;
        if(dig1!=0)
            xx=xx*10+dig1;
            x/=10;
    }
    return xx;
}

int main()
{
    long long x,y;
    cin>>x>>y;
    long long c=x+y;
   long long xx= darVuelta(x),yy=darVuelta(y),cc=darVuelta(c);

    if(quitarZeros(xx)+quitarZeros(yy)==quitarZeros(cc))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
