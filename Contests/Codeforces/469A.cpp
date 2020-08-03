#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int x[200];
    int y[200];
    cin>>x[0];
    for(int i=1;i<=x[0];i++)
        cin>>x[i];

    cin>>y[0];
    for(int i=1;i<=y[0];i++)
        cin>>y[i];

    int aa=1;

    for(int i=x[0]+1;i<x[0]+y[0]+1;i++)
    {
        x[i]=y[aa];
        aa++;
    }



    int q=1;
    bool a=false;
    for(int i=1;i<x[0]+y[0]+2;i++)
    {
        if(q<=n)
        {

          if(x[i]==q)
          {
              i=-1;q++;
          }
        else
        {
            if(i==x[0]+y[0]+1)
                a=true;
        }


        }



    }

    if(a==false)
        cout<<"I become the guy."<<endl;
    else
        cout<<"Oh, my keyboard!"<<endl;



    return 0;

}
