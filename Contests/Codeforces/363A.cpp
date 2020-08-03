#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string v="OO|OOOOO";
    if(n==0)
        cout<<"O-|-OOOO"<<endl;
    while(n!=0)
    {
        int dig=n%10;
        n/=10;
        if(dig==5)
        {
            v[0]='-';
            v[3]='-';
        }
        else
        {
            if(dig<5)
            {
           v[3+dig]='-';
           v[1]='-';
            }

            else
            {
            v[0]='-';
            v[3+dig-5]='-';
            }


        }
         cout<<v<<endl;
            v="OO|OOOOO";

    }
    return 0;
}
