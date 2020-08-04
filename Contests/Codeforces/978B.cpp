#include <iostream>

using namespace std;

int main()
{
    int n,c=0,ans=0;
    string  x;
    cin>>n>>x;
    bool sw=0;
    for(int i=0;i<n;i++)
    {
        c=0;
        while(x[i]=='x' && i!=n)
        {
            c++;
            i++;
            sw=1;
        }
        if(sw && c>2)
        {
            sw=0;
            ans+=abs(c-2);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
