#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,s1,s2,s3;
    cin>>s1>>s2>>s3;
    cout<<(sqrt(s1*s2/s3)+sqrt(s1*s3/s2)+sqrt(s2*s3/s1))*4<<endl;
    return 0;
}
