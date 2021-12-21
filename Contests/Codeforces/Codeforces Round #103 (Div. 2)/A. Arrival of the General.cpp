#include<bits/stdc++.h>
using namespace std;

int mayor(int v[],int n)
{
    int may=v[0];
    for(int i=0;i<n;i++)
        if(may<v[i])
            may=v[i];

    return may;
}

int menor(int v[],int n)
{
    int men=v[0];
    for(int i=0;i<n;i++)
        if(men>v[i])
            men=v[i];

    return men;
}

int main()
{
    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++)
        cin>>v[i];

    int may=mayor(v,n);
    int men=menor(v,n);
    int posMay=0,posMen=0;
    bool a=false;
    bool b=false;


    int f=0,ff=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==may & a==false)
           {
             posMay=i;
             a=true;
           }

        if(v[i]==men)
            {
                posMen=i;
                b=true;
            }

    }
for(int i=0;i<n;i++)
    {
            if(a==true & b==true)
            {

                if(posMay>posMen)
                    {
                        f=posMay;
                        ff=n-(posMen+1);
                        cout<<f+ff-1<<endl;

                    }
                else
                    {
                        f=posMay;
                        ff=n-(posMen+1);
                        cout<<f+ff<<endl;
                    }
                    break;
            }
    }


    return 0;
}
