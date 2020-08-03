#include <iostream>

using namespace std;

int main()
{
    int n,t;
    cin>>n>>t;
    int v[n+1];
    for(int i=1;i<n;i++)cin>>v[i];


    int i=1;
    while(true)
    {
        i+=v[i];
        if(i==t)
            break;

        if(i>t)
            break;
    }

     if(i==t)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}