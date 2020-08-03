#include<bits/stdc++.h>
using namespace std;

void sort (int n,int x[])
{
    int aux=0;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(x[i]>x[j])
                {
                   aux=x[i];
                   x[i]=x[j];
                   x[j]=aux;

                }
}

void print(int n,int x[])
{

    for(int i=0;i<n;i++)
        cout<<x[i]<<" ";

}
int main()
{
    int n,m;
    cin>>n>>m;

    if(n>=2 & m<=50)
    {
        int x[m];
        for(int i=0;i<m;i++)
            cin>>x[i];

        sort(m,x);

        int men=x[0+n-1]-x[0];

        for(int i=0;i<m-n+1;i++)
            {

                if(x[i+n-1]-x[i]<men)
                   men=x[i+n-1]-x[i];

            }

            cout<<men<<endl;
    }



    return 0;

}
