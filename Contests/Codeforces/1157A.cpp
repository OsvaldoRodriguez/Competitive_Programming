#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    set<int> s;
    s.insert(n);
    s.insert(1);
    bool sw=1;
    while(true)
    {
        n++;
        if(n%10!=0)
            s.insert(n);
        while(n%10==0)
            n/=10;
        if(n%10!=0)
            s.insert(n);
        if(n==9 and sw)
        {
            n=1;
            sw=0;
        }
        if(n==9 && !sw)
            break;
    }
    cout<<s.size()<<"\n";
    return 0;
}
