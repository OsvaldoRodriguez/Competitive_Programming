#include <iostream>

using namespace std;
typedef long long ll;
int main()
{
    ll p,c=0,pre=1;
    cin>>p;
    for(int i=1;i<p;i++)
    {
        bool sw=1;
        pre=1;
        for(int j=1;j<p-1;j++)
        {
            pre=(pre*i)%p;
            if(pre==1)
            {
                sw=0;
                break;
            }
        }
        if(sw)
        {
            pre*=i;
            pre%=p;
            if(pre==1)
            {
                c++;
                sw=0;
            }
        }


    }
    cout<<c<<"\n";
    return 0;
}
