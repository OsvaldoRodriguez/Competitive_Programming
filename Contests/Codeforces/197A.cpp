#include <iostream>

using namespace std;

int main()
{
    int b,h,r;
    while(cin>>b>>h>>r)
    {
        if(2*r>min(h,b))
            cout<<"Second\n";
        else
            cout<<"First\n";

    }
        return 0;
}
