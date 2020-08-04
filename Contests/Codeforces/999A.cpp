#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,ans=0,x;
    cin>>n>>k;
    deque<int> c;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        c.push_back(x);
    }

    bool sw=1,sw1=1;
    while(!c.empty() && (sw || sw1))
    {
        if(!c.empty() and c.back()<=k)
        {
            ans++;
            c.pop_back();
        }
        else
            sw=0;
        if(!c.empty() and c.front()<=k)
        {
            ans++;
            c.pop_front();
        }
        else
            sw1=0;

        if(c.empty())
        {
            sw=0;
            sw1=0;
        }
    }
    cout<<ans<<"\n";


    return 0;
}
