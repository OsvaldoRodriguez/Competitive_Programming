#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s,t;
    getline(cin,s);
    getline(cin,t);

    int ans=0;
    for(int i=0;i<=t.size();i++)
    {
        if(s[ans]==t[i])
            ans++;
    }

    cout<<ans+1<<endl;
    return 0;
}
