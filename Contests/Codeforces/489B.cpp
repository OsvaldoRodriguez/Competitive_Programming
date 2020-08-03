#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,m;
    cin>>n;
    int v1[n];
    for(int i=0;i<n;i++)
        cin>>v1[i];
    cin>>m;
    int v2[m];
    for(int i=0;i<m;i++)
        cin>>v2[i];

    sort(v1,v1+n);
    sort(v2,v2+m);

    int i=0,j=0,c=0;
    while(i<n && j<m)
    {
        if(abs(v1[i]-v2[j])<=1)
            {c++;i++;j++;}
        else
        if(v1[i]<v2[j])
            i++;
        else
            j++;

    }
    cout<<c<<endl;
    return 0;
}
