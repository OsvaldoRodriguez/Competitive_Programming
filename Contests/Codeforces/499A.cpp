#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){

    int n,x;
    cin>>n>>x;
    bool a =true;
    int i,l,r,c=1,d=0;
    for(i=1;i<=n;i++)
    {
        if(a)
        cin>>l>>r;
        if(x+c<=l)
        {
            c+=x;
            a=false;
            i--;
        }

        else
        {
            d+=r-c+1;
            c=r+1;
            a=true;
        }
    }

    cout<<d<<endl;
    return 0;
}
