#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    if(3*n-k<0)
        cout<<0<<endl;
    else
    cout<<3*n-k<<endl;
    return 0;
}
