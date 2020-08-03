#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;cin>>n;
    int par=2,impar=1;
    bool a=true;
    if(n%2!=0)
        cout<<-1<<endl;
    else
    {
        for(int i=1;i<=n;i++)
    {
        if(a)
        {
            cout<<par<<" ";
            a=false;
            par+=2;
        }
        else
        {
            cout<<impar<<" ";
            a=true;
            impar+=2;
        }

    }
    }

    return 0;
}
