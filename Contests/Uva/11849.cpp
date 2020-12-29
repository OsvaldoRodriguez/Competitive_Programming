#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> s;
    int n,m,x,c,t;
    while(cin>>n>>m && n!=0 && m!=0)
    {
        c=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            s.insert(x);
        }

        for(int i=0;i<m;i++)
        {
            cin>>x;
            t=s.size();
            s.insert(x);
            if(t==s.size())
                c++;
        }
        s.clear();
        cout<<c<<"\n";
    }
    return 0;
}
