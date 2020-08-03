#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int res=(n+1)/2;
    int ans=(res+m-1)/m*m;
    if(ans>n)
        cout<<-1<<endl;
    else
    cout<<ans<<endl;
    return 0;
}
