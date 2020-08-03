#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int w,q=1,aux1=0,aux2=0,aux3=0;
    for(int i=1;i<=n;i++)
    {
        cin>>w;
        switch(q)
        {
        case 1:aux1+=w; q++; break;
        case 2:aux2+=w; q++;break;
        case 3:aux3+=w; q=1;break;
        }
    }

    if(aux1>aux2 && aux1>aux3 )
    {cout<<"chest"<<endl;}

     if(aux2>aux1 && aux2>aux3 )
    {cout<<"biceps"<<endl;}

     if(aux3>aux1 && aux3>aux2 )
    {cout<<"back"<<endl;}

    return 0;
}
