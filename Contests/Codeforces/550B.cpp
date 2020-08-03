#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,l,r,y,x,c,mx,mn,s;
    cin>>n>>l>>r>>x;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>y;
        v.push_back(y);
    }
    int p=0;

    for(int i=0;i<(1<<n);++i)
    {
        s=c=0;
        mx=0;mn=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {

                s+=v[j];
                mx=max(mx,v[j]);
                mn=min(mn,v[j]);
                c++;
            }

        }
         if(s>=l && s<=r && (mx-mn)>=x && c>1)
                p++;
    }

    cout<<p<<endl;

    return 0;
}
