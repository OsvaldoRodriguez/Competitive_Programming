#include <bits/stdc++.h>

using namespace std;

int main()
{
    int y,k,n ;
    cin>>y>>k>>n ;
    int c = y%k ;
    int a = k-c ;
    bool b = false ;
    int i = 0 ;
    while((i*k+a)<=(n-y))
    {
        b=true;
        cout<<(i*k+a)<<" ";
        i++;
    }
    if (!b)cout<<-1<<endl ;
    return 0 ;

}
