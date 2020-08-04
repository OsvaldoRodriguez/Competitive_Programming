#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    map<string,int> m;
    string x,cmp="11";
    cin>>n>>x;
    for(int i=0;i<n-1;i++)
    {
        cmp[0]=x[i];
        cmp[1]=x[i+1];
        m[cmp]++;
    }
    string ans="";
    int may=-1;
    for(auto i=m.begin();i!=m.end();i++)
    {
        if(i->second>may)
        {
            may=i->second;
            ans=i->first;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
