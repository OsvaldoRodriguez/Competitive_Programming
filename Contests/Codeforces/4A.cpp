#include <bits/stdc++.h>

using namespace std;

int main()
{
    int z;
    cin>>z;
    if(1<=z & z<=100)
    {
        if(z==2)
            cout<<"NO"<<endl;
        else
            if(z%2==0)
            cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;

    }
    return 0;
}
