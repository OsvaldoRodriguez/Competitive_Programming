#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,k;
    map<int,int> m;
    cin>>n>>k;
    int v[n];
    for(int i=0;i<n;i++)
    {
        cin>>x;
        m[x]++;
        v[i]=x;
    }
    if(m.size()>=k)
    {
        cout<<"YES\n";
        int ans=0;
        for(int i=0;i<n && ans<k;i++)
        {
            if(m[v[i]]>=1)
            {
                cout<<i+1<<" ";
                m[v[i]]=0;
                ans++;
            }
        }
    }
    else
        cout<<"NO\n";

    return 0;
}
