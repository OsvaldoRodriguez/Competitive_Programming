#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    bool a=true;

    if(1000>=n & 1<=n)
    {
            if(n%4==0 || n%7==0 || n%47==0)
                cout<<"YES"<<endl;
            else
            {
                while(n!=0)
                    {
                        if(n%10!=7 && n%10!=4)
                            {
                                cout<<"NO"<<endl;
                                a=false;
                                break;

                            }
                            n/=10;

                    }

            if(a==true)
                cout<<"YES"<<endl;
            }
    }
return 0;
}
