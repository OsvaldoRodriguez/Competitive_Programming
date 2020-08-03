#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int x[n],y[n],a=0,b=0;
    bool sw=true;
    for(int i=0;i<n*2;i++)
    {
        if(sw)
        {
            cin>>x[a];
            a++;
            sw=false;
        }
        else
        {
            cin>>y[b];
            b++;
            sw=true;
        }
    }

    int cont=0;
    for(int i=0;i<n;i++)
    {
        bool upper=false,lower=false,right=false,left=false;
       for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                if(x[i]<x[j] && y[i]==y[j])
                            right=true;
                if(x[i]>x[j] && y[i]==y[j])
                            left=true;
                if(x[i]==x[j] && y[i]>y[j])
                            lower=true;
                if(x[i]==x[j] && y[i]<y[j])
                            upper=true;
            }
        }
        if(upper && lower && right && left)
            cont++;
    }

    cout<<cont<<endl;

    return 0;
}
