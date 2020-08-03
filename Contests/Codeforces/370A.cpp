#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,x,y,torre,rey,alfil;
    while(cin>>a>>b>>x>>y)
    {
        if(a==x && b==y)
            torre=0;
        else
            if(a==x || b==y)
                torre=1;
            else
                torre=2;

        if((a+b)%2!=(x+y)%2 || (a==x && b==y))
            alfil=0;
        else
            if(abs(x-a)==abs(y-b))
                alfil=1;
            else
                alfil=2;

        if(a==x && b==y)
            rey=0;
        else
            if(a==x || b==y)
                rey=max(abs(x-a),abs(y-b));
            else
                rey=max(abs(x-a),abs(y-b));

        cout<<torre<<" "<<alfil<<" "<<rey<<endl;
    }
    return 0;
}
