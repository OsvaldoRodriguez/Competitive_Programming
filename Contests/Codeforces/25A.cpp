#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int v[n+1];
    for(int i=1;i<=n;i++)
        cin>>v[i];


int cp=0,ci=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i]%2==0)
            cp++;
        else
            ci++;

    }

    if(cp==1)
        for(int i=1;i<=n;i++)
            if(v[i]%2==0)
                cout<<i<<endl;

     if(ci==1)
        for(int i=1;i<=n;i++)
            if(v[i]%2==1)
                cout<<i<<endl;

    return 0;
}
