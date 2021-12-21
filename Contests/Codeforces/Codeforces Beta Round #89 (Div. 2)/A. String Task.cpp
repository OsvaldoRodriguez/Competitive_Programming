#include <bits/stdc++.h>
using namespace std;
int main()
{
    string x;
    getline(cin,x);
    if( x.size()<=100)
        for(int i=0;i<x.size();i++)
            {
                x[i]=tolower(x[i]); //CONVIERTE MINUSCULAS

            }
        for(int i=0;i<x.size();i++)
            {
                if(x[i]!='a'& x[i]!='e'&x[i]!='i'&x[i]!='o'&x[i]!='u'&x[i]!='y')
                    cout<<"."<<x[i];
            }

    return 0;
}
