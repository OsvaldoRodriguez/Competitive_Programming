#include <iostream>

using namespace std;
typedef long long ll;
ll f(ll n)
{
    return n*(n+1)/2;
}
int main()
{
    ll n;
    cin>>n;
    ll a=0,b=100001,m;
    while(b-a>1)
    {
        m=(a+b)/2;
        if(f(m)>=n)
            b=m;
        else
            a=m;
    }
    a=1;
    bool sw=0;
    while(a!=b)
    {
        if(f(a)+f(b)==n)
        {
            sw=1;
            break;
        }
        else
            if(f(a)+f(b)>n)
                b--;
            else
                a++;
    }
        if(f(a)+f(b)==n)
            sw=1;
        if(sw)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    return 0;
}
