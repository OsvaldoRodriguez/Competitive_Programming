#include <iostream>

using namespace std;

int main()
{
    string a;
    getline(cin,a);
    string b="";
    for(int i=0;i<a.size();i++)
        if(a[i]!=' ')
            b+=a[i];
    int i=b.size()-2;
    b[i]=tolower(b[i]);

    if(b[i]=='a' || b[i]=='e' || b[i]=='i' || b[i]=='o' || b[i]=='u' || b[i]=='y')
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
