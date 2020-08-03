#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,menor=1000000000,opr=0;
    cin>>n;
    int v[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
        }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=v[i];j++)
        {
            cin>>m;
           opr+=m*5;
        }
        opr+=(15*v[i]);
        //cout<<opr<<endl;
        if(opr<menor)
            menor=opr;
        opr=0;

    }


    cout<<menor<<endl;
    return 0;
}
