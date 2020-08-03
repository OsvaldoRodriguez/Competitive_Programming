#include <iostream>

using namespace std;
const int N=453;
int v[N];
int main()
{
    int c=1;
    v[0]=v[1]=0;
    for(int i=2;i<N-3;i+=4)
    {
            v[i]=v[i+1]=c;
            v[i+2]=-1*c;
            v[i+3]=-1*c;
       c++;
    }

    c=0;
    int a,b;
    cin>>a>>b;///v[i] v[i-1]  v[i+1] v[i]

        bool sw=1;
        c=0;
        for(int i=1;i<453;i++)
        {
            if(sw)
            {
                int minix=min(v[i],v[i+1]);
                int mayx=max(v[i],v[i+1]);
                if((minix<=a && a<=mayx && v[i-1]==b))
                {
                    cout<<c<<endl;
                    break;
                }
                sw=0;
            }
            else
            {
                int miniy=min(v[i-1],v[i]);
                int mayy=max(v[i-1],v[i]);
                if(miniy<=b && b<=mayy && v[i+1]==a)
                {
                    cout<<c<<endl;
                    break;
                }
                sw=1;
            }
            c++;
        }

    return 0;
}
