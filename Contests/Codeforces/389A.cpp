#include <bits/stdc++.h>

using namespace std;

void seleccion(int v[],int n)
{
    for(int i=0;i<n;i++)
    {
        int m=i;
        for(int j=i+1;j<n;j++)
            if(v[j]>v[m])
                m=j;

        int aux=v[i];
            v[i]=v[m];
            v[m]=aux;
    }
}

void mostrar(int v[],int n)
{
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
}
int main()
{
    int n,sum=0,cont=0;
    cin>>n;
    int x[n];
    for(int i=0;i<n;i++)
        cin>>x[i];

    seleccion(x,n);
    //mostrar(x,n);cout<<" ordenado"<<endl;

    for(int i=0;i<n-1;i++)
    {
        if(x[i]>x[i+1])
        {
            x[i]=x[i]-x[i+1];

        }
        else
        {
            if(cont>n)
                break;
        }


        if(i==n-2)
        {
            cont++;
            seleccion(x,n);
            //mostrar(x,n);cout<< "parcial"<<endl;
            i=-1;
        }




    }
        //mostrar(x,n);cout<<endl;
    for(int k=0;k<n;k++)
    {
        sum+=x[k];
    }

    cout<<sum<<endl;


    return 0;
}
