#include <iostream>
using namespace std;
int busca(char x,char v[])
{
    int pos;
    for(int i=0;i<9;i++)
    {
        if(v[i]==x)
            pos=i;
    }

    return pos;
}
int main()
{
    char v[9]={'6', '7', '8', '9', 'T', 'J', 'Q', 'K' , 'A'};
    char x;
    string a,b;
    cin>>x;
    cin>>a>>b;

       if(x==a[1] && x==b[1])
       {
            if(busca(a[0],v)>busca(b[0],v))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
       }
       else
       {
            if(x==a[1])
                cout<<"YES"<<endl;
            else
            {
                if(a[1]==b[1])
                {
                     if(busca(a[0],v)>busca(b[0],v))
                        cout<<"YES"<<endl;
                    else
                        cout<<"NO"<<endl;
                }
                else
                    cout<<"NO"<<endl;
            }

       }

    return 0;
}
