#include <bits/stdc++.h>
using namespace std;
int main()
{

    int c,t=0;
    cin>>c;
    string x;
    if(c<=100)
    while(t<=c)
    {
        getline(cin,x);
        if(x.size()>10)
           {
             if(x.size()<=100)
            cout<<x[0]<<x.size()-2<<x[x.size()-1]<<endl;
           }
        else
            cout<<x<<endl;

        t++;
    }



    return 0;

}
