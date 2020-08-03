#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,cont=1,aux1=0,aux2=0;
    cin>>n;
    string y="",z="";

    bool sw=true;
    while(cont<=n)
    {
        string x;
        cin>>x;
        if(sw)
        {
            y=x;
            sw=false;
        }
        if(x==y)
            aux1++;
        else
        {
            aux2++;
             z=x;
        }
        cont++;
    }


      if(aux1>aux2)
        cout<<y<<endl;
        else
            cout<<z<<endl;


    return 0;
}
