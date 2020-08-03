#include <bits/stdc++.h>
using namespace std;

int burbuja(int n,int q[])
{
    int aux;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(q[i]<q[j])
            {
                aux=q[i];
                q[i]=q[j];
                q[j]=aux;
            }

        }
    }
}

int main()
{
    int n,r=0,q=1,sum=0;
    cin>>n;
    int w[n];
    for(int i=0;i<n;i++)
        cin>>w[i];

        burbuja(n,w);

    for(int i=0;i<n;i++)
        r+=w[i];

        sum=w[0];

    for(int j=0;j<n;j++)
        if(sum>r-sum)
            {cout<<q<<endl;break;}
        else
        {
            sum+=w[j+1];q++;
        }


    return 0;
}
