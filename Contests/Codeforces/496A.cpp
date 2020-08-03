#include <bits/stdc++.h>

using namespace std;
int a=1;

void recorrer(int v[],int n,int m[])
{
    int j=0;
    for(int i=0;i<n;i++)
        {
            if(i!=a)
            {
              m[j]=v[i];

            j++;
            }

        }

        a++;


}

void mostrar(int m[],int n)
{
    for(int i=0;i<n-1;i++)
        cout<<m[i]<<" ";
}

int main()
{
   int n;
   cin>>n;
   int v[n];
   int m[n-1];
   for(int i=0;i<n;i++)
    cin>>v[i];


    int may=0,mini=100000;
    for(int i=0;i<n-2;i++)
    {
        recorrer(v,n,m);

        for(int j=0;j<n-2;j++)
        {
            if(m[j+1]-m[j]>may)
                may=m[j+1]-m[j];

        }

        if(mini>may)
            mini=may;
            may=0;


    }

cout<<mini<<endl;







    return 0;
}
