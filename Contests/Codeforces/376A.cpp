#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    long long izq=0,der=0,mid;

    for(int i=0;i<s.size();i++)
        if(s[i]=='^')
        {
            mid=i;
            break;
        }

    for(int i=0;i<mid;i++)
        if(s[i]!='=')
            izq+=(mid-i)*(s[i]-'0');

    for(int j=mid+1;j<s.size();j++)
        if(s[j]!='=')
            der+=(j-mid)*(s[j]-'0');

    if(izq==der)
        cout<<"balance"<<endl;
    else
    {
        if(izq>der)
            cout<<"left"<<endl;
        else
            cout<<"right"<<endl;
    }
    return 0;
}
