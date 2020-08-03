#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;

    long long m[n][2];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>m[i][j];
        }
    }

    long long may=-9999999999;
    long long prob=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
                if(m[i][1]>k)
                    prob=m[i][0]-(m[i][1]-k);
                else
                    prob=m[i][0];

                 if(may<prob)
                        may=prob;

        }

    }

    cout<<may<<endl;
    return 0;
}
