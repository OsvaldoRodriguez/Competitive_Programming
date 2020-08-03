#include <bits/stdc++.h>
typedef long double ld;
using namespace std;
int v[1001];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>v[i];

    sort(v,v+n);
    double mx=max(v[0],m-v[n-1]);
    for(int i = 1; i < n; ++i)
        mx=max(mx,(double)(v[i]-v[i-1])/2.0);

    printf("%.8f\n",mx);
    return 0;
}
