#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int m[n];
    int v[n];

    bool sw=true;
    int a=0,b=0;
    for(int i=0;i<n*2;i++)
    {
        if(sw)
        {
            cin>>m[a];
            a++;
            sw=false;
        }
        else
        {
            cin>>v[b];b++;sw=true;
        }

    }

    bool aa=false;
    int cont=0;
    for(int i=0;i<a;i++)
    {
       if(m[i]!=v[i])
        {
            aa=true;
            break;
        }

    }

    if(aa)
        cout<<"Happy Alex"<<endl;
    else
        cout<<"Poor Alex"<<endl;


    return 0;
}
