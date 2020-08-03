#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    char mm[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mm[i][j];
        }
    }

    int may=mm[0][0],mejor=0,best=0,cont=0;
    bool sw=true,sww=true,s=true;


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(may!=mm[i][j])
           {
             sww=false;
           break;
           }

        }
    }

    if(sww && n!=1 && m!=1)
        cout<<n<<endl;
    else
    {
    may=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
           {
               //cout<<"p "<<mm[i][j]<<"  <  "<<mm[k][j]<<"\t"<<k<<" = "<<n-1<<"\t mejor\t"<<mejor<<"\t  cont   \t"<<cont<<"\t"<<endl;
               if(mm[i][j]<mm[k][j] && s)
                    s=false;

           }

            if(s)
            mejor++;
            s=true;


        }
        if(mejor!=0)
            best++;
        mejor=0;
        //cout<<best<<" n=n"<<endl;
    }
    cout<<best<<endl;
    }
    return 0;
}

