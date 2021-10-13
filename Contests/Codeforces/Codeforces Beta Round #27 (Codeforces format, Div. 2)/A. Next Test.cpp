#include <iostream>

using namespace std;
int v[3002];
int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v[x]=1;
    }
    for(int i=1;i<3002;i++)
        if(v[i]==0)
    {
        cout<<i<<"\n";
        break;
    }
    return 0;
}
