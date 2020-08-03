#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r1,r2,c1,c2,d1,d2;
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    int a,b,c,d;
    a=((2*r1-c2-d2+r2)/2);
    b=((c2+d2-r2)/2);
    c=((c1+d2-r1)/2);
    d=((2*r2-c1-d2+r1)/2);


    if(a!=b  && a!=c && a!=d && b!=c && b!=d && c!=d &&a<10 && b<10 && c<10 && d<10 && a>0 && b>0 && c>0 &&d>0)
    cout<<a<<" "<<b<<endl<<c<<" "<<d<<endl;
    else
        cout<<-1<<endl;

    return 0;
}
