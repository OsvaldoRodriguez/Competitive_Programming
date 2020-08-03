#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int v[n+1];
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    bool sw=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(v[i]==(v[j]+v[k]) && i!=j && k!=i && j!=k)
    {
        printf("%d %d %d\n",i,j,k);
        sw=1;
        j=n;i=n;break;
    }
    if(!sw)
        printf("-1\n");
    return 0;
}
