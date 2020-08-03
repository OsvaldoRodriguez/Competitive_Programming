#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    bool a=true;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='W' || s[i+1]!='U' || s[i+2]!='B')
        {

            while(a==true)
            {

                if(s[i]!='W' || s[i+1]!='U' || s[i+2]!='B')
                    {
                        if(i==s.size())
                            break;
                        else
                        {
                            cout<<s[i];
                            i++;
                        }



                    }

                else
                    {
                        cout<<" ";
                        i+=2;
                        a=false;
                    }


            }
            a=true;

        }
        else
            i+=2;
    }

    return 0;
}
