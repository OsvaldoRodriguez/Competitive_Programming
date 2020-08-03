#include <bits/stdc++.h>

using namespace std;
string con(long long x)
{
    string a="";
    while(x>0)
    {
        if(x%2==0)
            a+="0";
        else
            a+="1";

        x/=2;
    }

    return a;
}
int main()
{
    long long n,k;
    cin>>n>>k;
    string q=con(k);
    for(int i=0;i<q.size();i++)
    {
        if(q[i]=='1')
        {
            cout<<i+1<<endl;
            break;
        }
    }




    return 0;
}
