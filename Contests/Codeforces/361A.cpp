#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int m[n][n]={0};

    for(int i=0;i<n;i++)
        m[0][i]=0;



    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(i==j)
               cout<<k<<" ";
               else
                cout<<m[i][j]<<" ";

        cout<<endl;
    }


    return 0;
}
