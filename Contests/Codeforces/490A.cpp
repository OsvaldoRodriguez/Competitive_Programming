#include <bits/stdc++.h>

using namespace std;

int cont=0,vv1=1;
void formar_Eq(int v[],int n,int vv[])
{
int p1=0,p2=0,p3=0;
    for(int i=1;i<=n;i++)
    {

        if(v[i]==1 &&v[i]!=0)
            p1=i;

        if(v[i]==2&&v[i]!=0)
            p2=i;

        if(v[i]==3&&v[i]!=0)
            p3=i;

            if(p1!=0 && p2!=0 &&p3!=0)
            {
                cont++;
                vv[vv1]=p1;
                vv1++;
                vv[vv1]=p2;
                vv1++;
                vv[vv1]=p3;
                vv1++;

                v[p1]=v[p2]=v[p3]=0;
                i=0;

                p1=0,p2=0,p3=0;
            }


        }







}

void mostrar(int vv[],int cont)
{
    int a=4;
    cout<<cont<<endl;
    for(int i=1;i<=cont*3;i++)
        {
           if(a==i)
           {
            cout<<endl;
            a+=3;
           }

        cout<<vv[i]<<" ";
        }

}

int main()
{
    int n;
    cin>>n;
    int v[n+1];

    int vv[n/3*3+1];



    for(int i=1;i<=n;i++)
        cin>>v[i];

    bool a=false,b=false,c=false;

    for(int i=1;i<=n;i++)
    {
        if(v[i]==1)
            a=true;
        if(v[i]==2)
            b=true;
        if(v[i]==3)
            c=true;

            if(a&&b&&c)
                break;


    }


    if(a&&b&&c)
    {

        formar_Eq(v,n,vv);
        mostrar(vv,cont);
    }
    else
        cout<<0<<endl;

    return 0;
}
