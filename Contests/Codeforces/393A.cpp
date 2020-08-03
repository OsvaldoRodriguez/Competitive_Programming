#include <iostream>

using namespace std;

int main()
{
    string x;
    while(cin>>x)
    {
       int cn=0,ci=0,ct=0,ce=0;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='n')
                cn++;
            if(x[i]=='i')
                ci++;
            if(x[i]=='t')
                ct++;
            if(x[i]=='e')
                ce++;
        }
        //cout<<cn<<" "<<ci<<" "<<ct<<" "<<ce<<" \n";
        int res=min(cn/3,min(ce/3,min(ci,ct)));
        //cout<<res<<" primera respuesta\n";
        int posible=cn/2;
        if(cn%2==0 && cn!=0)
            posible--;
        if(posible*2+1<=cn)
            res=min(posible,min(ce/3,min(ci,ct)));
        cout<<res<<"\n";
    }
    return 0;
}
