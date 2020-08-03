#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,sumpar=0,sumimpar=0;
    cin>>n;
    int x[n];int y[n];

    for(int i=0;i<n;i++)
    {
           cin>>x[i]>>y[i];

    }


    for(int i=0;i<n;i++)
    {
        sumpar+=x[i];
        sumimpar+=y[i];
    }


    if(sumpar%2==0 && sumimpar%2==0)
        cout<<0<<endl;
    else
    {
        bool sw=false;
            if(sumpar%2!=0 || sumimpar%2!=0)
            {
                for(int i=0;i<n;i++)
                {
                    if((sumpar-x[i]+y[i])%2==0 && (sumimpar-y[i]+x[i])%2==0)
                    {
                        sw=true;
                        break;
                    }
                }
            }

            if(sw)
                cout<<1<<endl;
            else
                cout<<-1<<endl;
    }
    return 0;
}
