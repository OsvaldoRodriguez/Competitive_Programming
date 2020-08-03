#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,men=0,men1=10;
    cin>>n>>m;
    int v[n+1][m+1];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        cin>>v[i][j];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i][j]==1)
            {
                if(1<i && i<n && 1<j && j<m)
                {
                    if(m==2)
                        men=2;
                    else
                        men=4;
                }
                else
                   men =2;

                if(men1>men)
                    men1=men;
            }

        }

    }

    cout<<men1<<endl;
    return 0;
}
