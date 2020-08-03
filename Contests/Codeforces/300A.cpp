#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n,pos=0,pos2=0,cont=0,cont30=0;
    cin>>n;
    int x[n];
    for(int i=0;i<n;i++)
        cin>>x[i];

        bool sw=true;
        for(int i=0;i<n;i++)
        {

            if(x[i]==0)
                cont30++;
            if(x[i]<0)
            {
                cont++;
                if(x[i]!=0 &&sw)
                {
                  pos=i;
                  sw=false;
                }


            }
        }

      //  cout<<cont<<" negativos"<<endl;
        cout<<1<<" "<<x[pos]<<endl;
        if(cont%2==0)
        {
            bool w=true;
            cout<<n-cont30-2<<" ";
            for(int i=0;i<n;i++)
            {

                if(i!=pos && x[i]<0)
                {
                   pos2=i;
                   break;
                }
            }

            for(int i=0;i<n;i++)
            {

                if(i!=pos &&i!=pos2&& x[i]!=0)
                    cout<<x[i]<<" ";
            }

             cout<<endl<<cont30+1<<" ";
             for(int i=0;i<cont30;i++)
                cout<<0<<" ";
             cout<<x[pos2]<<" ";
        }

        else
        {
            cout<<n-cont30-1<<" ";
            for(int i=0;i<n;i++)
            {

                if(i!=pos && x[i]!=0)
                    cout<<x[i]<<" ";
            }
            cout<<endl<<cont30<<" ";
             for(int i=0;i<cont30;i++)
                cout<<0<<" ";
        }





    return 0;
}
