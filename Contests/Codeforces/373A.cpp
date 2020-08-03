#include <bits/stdc++.h>
#define n 4
using namespace std;
void acomodar(int e,int v[])
{
    for(int i=1;i<=9;i++)
        if(e==i)
        v[i]+=1;
}
int main()
{
    int k,x;
    cin>>k;
    int q[10]={0};
    char m[n][n];

    //cout<<q[1]<<endl<<q[9]<<" vector"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>m[i][j];

    int cont=0;
     for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
                if( m[i][j]!='.')
                    {
                        acomodar(m[i][j]-'0',q);
                        //cout<<m[i][j]-'0'+m[i][j]-'0'<<endl;

                    }


    bool sw=true;
    for(int i=1;i<=9;i++)
        if(q[i]>2*k)
    {
        sw=false;
        break;
    }



    if(sw)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
