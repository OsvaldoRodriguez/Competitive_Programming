#include<bits/stdc++.h>
using namespace std;
int main()
{
    string x;
    getline(cin,x);
    int a=0,b=0,c=0;
    for(int i=0;i<x.size();i++)
        {
            if(x[i]=='1')
                a++;
            if(x[i]=='2')
                b++;
            if(x[i]=='3')
                c++;
        }
        int aa=1,bb=1,cc=1;


        for(int i=1;i<=a+b+c;i++)
        {
            if(aa<=a)
                {
                    cout<<"1";aa++;
                }
            else
            {
                    if(bb<=b)
                         {cout<<"2";bb++;}
                    else
                         {cout<<"3";cc++;}

            }

                    if(i!=a+b+c)
                        cout<<"+";

        }




    return 0;
}
