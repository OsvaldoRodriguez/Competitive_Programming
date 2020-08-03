#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    string cad,cad2;

    for(int i=1;i<=m;i++)
    {
        cad+="#";
        if(i<m)
            cad2+=".";

    }

    int a=1;
    bool aa=true;
    for(int i=1;i<=n;i++)
    {
        switch(a)
        {
        case 1:cout<<cad<<endl;a++;break;
        case 2:

            if(aa)
            {
                cout<<cad2<<"#"<<endl;aa=false;
            }
            else
            {
                cout<<"#"<<cad2<<endl;aa=true;
            }
            a=1;

        break;

        }

    }

    return 0;
}
