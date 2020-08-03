#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    bool a=true;
    char m[103][103];
    memset(m,'*',sizeof(m));  ///llenando * la matriz

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>m[i][j];
        }

    }

int    cont=0;
    for(int i=1;i<=n && a;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(m[i-1][j]=='o')cont++;
            if(m[i+1][j]=='o')cont++;
            if(m[i][j+1]=='o')cont++;
            if(m[i][j-1]=='o')cont++;

            if(cont%2!=0)
                a=false;

        }

    }

    if(a)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
