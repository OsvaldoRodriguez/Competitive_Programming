#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,x;
    cin>>n>>m;
    vector<int> v1,v2;
    for(int i=0;i<n;i++)
    {
       cin>>x;
       v1.push_back(x);
    }

    for(int i=0;i<m;i++)
    {
        cin>>x;
        v2.push_back(x);
    }

    sort(v1.begin(),v1.end());
    for(int i=0;i<m;i++)
    {
        long long a=-1,b=n,m1;
        while(b-a>1)
        {
            m1=(a+b)/2;
            if(v1[m1]<=v2[i])
                a=m1;
            else
                b=m1;
        }

        cout<<a+1<<" ";
    }

    return 0;
}
