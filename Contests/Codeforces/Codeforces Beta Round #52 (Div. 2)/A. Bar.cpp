#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string a;
    int res=0;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        bool sw=0;
        for(int j=0;j<a.size();j++)
        {
            if(65<=a[j] && a[j]<=90)
            {
                sw=1;
                break;
            }
        }
        if(sw)
        {
            if(a=="ABSINTH" || a=="BEER" || a=="BRANDY" || a=="CHAMPAGNE" || a=="GIN" || a=="RUM" || a=="SAKE" || a=="TEQUILA" || a=="VODKA" || a=="WHISKEY" || a=="WINE" )
                res++;
        }
        else
        {
            int num=atoi(a.data());
            if(num<18)
                res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
