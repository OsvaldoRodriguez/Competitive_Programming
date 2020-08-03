#include<bits/stdc++.h>
using namespace std;

int min(int n,int m)
{
    if(n<m)
        return n;
    else
        return m;
}
int main()
{
    int n,m;
    cin>>n>>m;

    if(min(n,m)%2==0)
        cout<<"Malvika"<<endl;
    else
        cout<<"Akshat"<<endl;

    return 0;
}
