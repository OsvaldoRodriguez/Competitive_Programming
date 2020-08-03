#include <bits/stdc++.h>




using namespace std;



void insercion(int v[],int f[],int n)
{
    int j;

    ///burbuja


    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(v[j]<v[i])
        {
            int aux=v[i];
            v[i]=v[j];
            v[j]=aux;

            aux=f[i];
            f[i]=f[j];
            f[j]=aux;
        }

}


int main()
{
    int s,n;
    cin>>s>>n;
    int d[n],f[n];
    int b=0,c=0;
    bool a=true;
        for(int j=0;j<n*2;j++)
        {
            if(a==true)
            {
                cin>>d[b];b++;
                a=false;
            }
            else
            {
                cin>>f[c];c++;
                a=true;
            }

        }
    insercion(d,f,n);


      for(int j=0;j<n;j++)
        {
            if(d[j]<s)
            {
                s+=f[j];
                if(j==n-1)
                    cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
                break;
            }



        }




    return 0;
}

