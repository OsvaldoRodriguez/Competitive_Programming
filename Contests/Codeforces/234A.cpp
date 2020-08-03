#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    string a;
    cin>>a;
    for(int i=0;i<n/2;i++)
    {
        if(a[i]==a[n/2+i])
            cout<<i+1<<" "<<n/2+i+1<<endl;
        else
        {
            if(a[i]=='L')
                cout<<i+1<<" "<<n/2+i+1<<endl;
            else
                cout<<n/2+i+1<<" "<<i+1<<endl;
        }
    }
    return 0;
}
