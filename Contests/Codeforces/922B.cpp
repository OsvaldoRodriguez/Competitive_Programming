#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,c=0;
    cin>>n;
    for(int i=1;i<=n-2;i++)
        for(int j=i+1;j<=n-1;j++)
            for(int k=j+1;k<=n;k++)
                if((i^j)==k && i+j>k)
                    c++;

    cout<<c<<"\n";
    return 0;
}
