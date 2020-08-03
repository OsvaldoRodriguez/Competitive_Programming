#include<bits/stdc++.h>
using namespace std;
int  px,py;
int verifica(string x,string y)
{
    int s=0;
    bool sw=true;
    for(int i=0;i<x.size();i++)
        if(x[i]==y[i])
            s+=1;
        else
        {
           if(sw)
           {
               px=i;
               sw=false;
           }
           else
            py=i;
        }

    return (x.size()-s);

}
int main()
{
    string x,y;
    cin>>x>>y;

    if(x.size()!=y.size())
        cout<<"NO"<<endl;
    else
    {
        if(x==y)
            cout<<"YES"<<endl;
        else
        {
            ///cout<<verifica(x,y)<<endl;
            if(verifica(x,y)!=2)
                cout<<"NO"<<endl;
            else
            {
                if(verifica(x,y)==0)
                    cout<<"YES"<<endl;
                else
                {
                    //cout<<px<<" pos "<<py<<endl;
                    char aux=x[px];
                        x[px]=x[py];
                        x[py]=aux;

                    if(x==y)
                        cout<<"YES"<<endl;
                    else
                        cout<<"NO"<<endl;
                }

            }

        }


    }



    return 0;

}
