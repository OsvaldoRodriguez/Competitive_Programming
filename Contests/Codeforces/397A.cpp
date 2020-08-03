#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y;
    map<int,bool> m;
    cin>>n;
    bool sw=1;
    while(n--)
    {
        cin>>x>>y;
        while(x<y)
        {
            if(sw)
                m[x]=1;
            else
                m[x]=0;
            x++;
        }
        sw=0;
    }
    int res=0;
    for(auto i=m.begin();i!=m.end();++i)
        if(i->second)
            res++;

    cout<<res<<"\n";
    return 0;
}
