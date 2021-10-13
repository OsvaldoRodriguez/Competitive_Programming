#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a,b,x,k,t=3;
    cin>>x;
    k=x;
    while(t--)
    {
        cin>>a>>b;
        if(k==a)
            k=b;
        else
            if(k==b)
                k=a;

    }
    cout<<k<<"\n";
    return 0;
}
