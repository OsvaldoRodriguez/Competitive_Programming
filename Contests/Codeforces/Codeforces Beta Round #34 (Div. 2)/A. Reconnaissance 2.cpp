#include <iostream>
 
using namespace std;
 
int main()
{
    int n;cin>>n;int v[n+1];
    for(int i=1;i<=n;i++)
        cin>>v[i];
        bool sw=true;
    int men=abs(v[1]-v[n]);
    int l=1,r=n;
    for(int i=1;i<n;i++)
    {
        if(abs(v[i]-v[i+1])<men)
        {
            men=abs(v[i]-v[i+1]);
            l=i;
            r=i+1;
        }
    }
 
        cout<<l<<" "<<r<<endl;
    return 0;
}
