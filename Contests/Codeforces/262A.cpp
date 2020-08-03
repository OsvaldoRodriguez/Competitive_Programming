#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,c=0,num,cont=0,cont2=0;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        cin>>num;
        while(num!=0)
        {

            int dig=num%10;
            num/=10;
            if(dig==4 || dig==7)
                cont++;
        }
        if(cont>k)
            cont2++;

        cont=0;

    }

    cout<<n-cont2<<endl;
    return 0;
}
