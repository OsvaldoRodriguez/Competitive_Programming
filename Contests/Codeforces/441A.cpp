#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,v,ee=0;
    cin>>n>>v;
    int a[50];
    int s[50];
    for(int j=1;j<=n;j++)
    {
        int k;
        cin>>k;
        bool sw=true;
        for(int i=0;i<k;i++)
        {

            cin>>a[i];

            if(v>a[i] && sw)
            {
                sw=false;
                s[ee]=j;
                ee++;

            }

        }
    }

    cout<<ee<<endl;
   for(int i=0;i<ee;i++)
        cout<<s[i]<<" ";
    return 0;
}
