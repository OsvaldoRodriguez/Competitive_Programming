#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,t,m,l,r,cont1=0,cont2=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        {
            scanf("%d",&t);
            (t==1?cont1++:cont2++);
        }

        int lim=min(cont1,cont2)*2;
   while(m--)
   {
       scanf("%d%d",&l,&r);
       printf((r-l)%2==1 && r-l<lim?"1\n":"0\n");
   }



    return 0;
}
