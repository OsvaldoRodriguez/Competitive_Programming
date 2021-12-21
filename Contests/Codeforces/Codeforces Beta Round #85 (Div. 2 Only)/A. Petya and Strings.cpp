#include<bits/stdc++.h>
using namespace std;
int main()
{

    string x,y;
    getline(cin,x);
    getline(cin,y);

    for(int i=0;i<x.size();i++)
        x[i]=tolower(x[i]);
    for(int i=0;i<y.size();i++)
        y[i]=tolower(y[i]);

    if(x!=y)
    {
        if(x<y)
            cout<<"-1"<<endl;
        else
            cout<<"1"<<endl;

    }
    else
        cout<<"0"<<endl;
    return 0;
}
