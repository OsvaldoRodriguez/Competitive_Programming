#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    map<int,int> m;
    cin>>n;
    stack<int> s;
    int v[n];
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v[i]=x;
        m[x]++;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(m[v[i]]>=1)
        {
            s.push(v[i]);
            m[v[i]]=0;
        }
    }
    cout<<s.size()<<"\n";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
