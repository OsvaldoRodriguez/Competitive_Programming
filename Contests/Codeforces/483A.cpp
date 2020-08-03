#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long l,r;
    cin>>l>>r;




    if(l%2==0 && l+2<=r)
        cout<<l<<" "<<l+1<<" "<<l+2<<endl;
    else
    {
        if(l+3<=r)
            cout<<l+1<<" "<<l+2<<" "<<l+3<<endl;
        else
            cout<<-1<<endl;
    }







    return 0;
}
