#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> s;
    int n,x,cx=-1;
    cin>>n;
    bool sw1=1,sw2=1;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x==0 || x==100)
            s.push_back(x);
        else
            if(x<10 && sw1 )
            {
                s.push_back(x);
                sw1=0;
            }
            else
                if((x%10)==0 && sw2)
            {
                s.push_back(x);
                sw2=0;
            }
            else
                cx=x;
    }

    if(sw1 && sw2 && cx!=-1)
        s.push_back(cx);
    cout<<s.size()<<"\n";
    for(int i=0;i<s.size();i++)
        cout<<s[i]<<" ";
    return 0;
}
