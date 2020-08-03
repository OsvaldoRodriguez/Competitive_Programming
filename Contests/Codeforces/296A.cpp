#include <bits/stdc++.h>

using namespace std;
///retorna posicion del elemento mas repetido
int mayor(int v[],int n)
{
    int may=0,j=0;
    for(int i=0;i<n;i++)
        if(may<v[i])
            may=v[i];


     for(int i=0;i<n;i++)
        if(may==v[i])
             j=i;


    return j;
}

int main()
{
    int n;
    cin>>n;
    int x[n];
    int v[n];
    for(int i=0;i<n;i++)
        v[i]=1;
/*
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
        cout<<endl;
*/
    for(int i=0;i<n;i++)
        cin>>x[i];

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
            if (x[i]==x[j])
                v[i]=v[i]+1;


    }

   /// cout<<endl<<x[mayor(v,n)]<<endl;
    ///cout<<v[mayor(v,n)]<<endl;
    if(v[mayor(v,n)]<=(int)((n+1)/2))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
