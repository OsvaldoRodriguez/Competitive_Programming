#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,x;
    cin>>n;
    int v[n];
    memset(v,0,n*4);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>x;
            v[j]+=x;
        }

    }
    bool sw=true;
    for(int i=0;i<n;i++)
    {
        if(v[i]!=0)
        {
            sw=false;
            cout<<"NO\n";
            break;
        }
    }
    if(sw)
        cout<<"YES\n";
    return 0;
}
