#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m,a,b;
    while(cin>>n>>m>>a>>b)
    cout<<min((n%m)*b,(m-n%m)*a)<<"\n";
    return 0;
}
