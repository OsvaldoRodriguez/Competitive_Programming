#include <iostream>

using namespace std;

int main()
{
    int n,x,a=-2000000000,b=2000000000;
    cin>>n;
    string q,w;
    for(int i=0;i<n;i++)
    {
        cin>>q>>x>>w;
        if(w=="Y")
        {
           if(q=="<" && x<=b)
                b=x-1;
           if(q=="<="  && x<=b)
                b=x;
           if(q==">" && a<=x)
                a=x+1;
           if(q==">="&& a<=x)
                a=x;
        }
        else
        {
            if(q=="<" && a<=x)
                a=x;
           if(q=="<=" && a<=x)
                a=x+1;
           if(q==">" && b>=x)///<
                b=x;
           if(q==">=" && b>=x)
                b=x-1;
        }

    }
    if(b>=a)
    cout<<a<<endl;
    else
        cout<<"Impossible"<<endl;
    return 0;
}
