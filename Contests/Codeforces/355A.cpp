#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k,q=1;
    char d;
    string s="";
    cin>>k>>d;
    if(d-'0'==0)
    {
        if(k==1)
            cout<<0<<endl;
        else
            cout<<"No solution"<<endl;
    }
    else
    {

        s+=d;
        for(int i=1;i<k;i++)
            s+="0";

        cout<<s<<endl;
    }

    return 0;
}
