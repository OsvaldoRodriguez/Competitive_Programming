#include <bits/stdc++.h>

using namespace std;



void insercion(int v[],int n)
{
    int j;
    for(int i=1;i<n;i++)
    {
        int aux=v[i];
        for(j=i-1;j>=0&& v[j]>aux;j--)
            v[j+1]=v[j];
        v[j+1]=aux;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    int v[n],v2[m];
    for(int i=0;i<n;i++)
        cin>>v[i];

    for(int i=0;i<m;i++)
        cin>>v2[i];

    insercion(v,n);
    insercion(v2,m);

    int va=v[0],p=v[n-1],c=v2[0];

    if(max(2*va,p)<c)
        cout<<max(2*va,p)<<endl;
        else
            cout<<-1<<endl;




    return 0;
}
