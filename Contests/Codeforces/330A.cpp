#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;
    char m[r][c];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>m[i][j];
        }
    }

    int cont=0,cont2=0,aux1=0,aux2=0;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(m[i][j]=='.')
                aux1++;
        }
        if(aux1==c)
            cont++;
        aux1=0;

    }

    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            if(m[j][i]=='.')
                aux2++;
        }
        if(aux2==r)
            cont2++;
        aux2=0;

    }
    cout<<cont*c+cont2*r-cont*cont2<<endl;
    return 0;
}
