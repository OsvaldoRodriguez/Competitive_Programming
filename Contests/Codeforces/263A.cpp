#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a=6;
    int m[a][a];

    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>m[i][j];
        }

    }

    int c=0,f=0;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            if(m[i][j]==1)
                {

                    if(i>3)
                        c=i-3;
                    else
                        c=3-i;

                    if(j>3)
                        f=j-3;
                    else
                        f=3-j;
                break;
                }
        }


    }

    int sum=0;
    sum=c+f;
    cout<<sum<<endl;

    return 0;
}
