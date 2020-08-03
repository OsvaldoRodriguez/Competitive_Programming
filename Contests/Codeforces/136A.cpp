#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int v[n];

    for(int i=1;i<=n;i++)
        cin>>v[i];


    int q=1;
    int i=1;
    while(i<=n)
    {
        if(v[i]==q)
        {
            cout<<i<<" ";
            i=0;
            q++;
        }
        i++;
    }

    return 0;
}
