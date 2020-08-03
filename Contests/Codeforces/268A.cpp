#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int x[n];
    int y[n];
    int a=0,b=0;
    bool sw=true;
    for(int i=0;i<n*2;i++)
    {
        if(sw==true)
            {
                cin>>x[a];
                sw=false;
                a++;
            }
        else
        {
            cin>>y[b];
            sw=true;
            b++;
        }

    }
    int e=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j & x[i]==y[j])
                e++;


    cout<<e<<endl;
}
