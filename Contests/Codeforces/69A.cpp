#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x[n];
    int y[n];
    int z[n];
    int r=1,a=0,b=0,c=0;
    if(n>=1 & n<=100)
    {
       for(int i=0;i<n*3;i++)
        {
            switch(r)
            {
                case 1:
                   cin>>x[a];
                   a++;
                   r=2;

                break;
                case 2:
                    cin>>y[b];
                   b++;
                   r=3;


                break;
                case 3:
                    cin>>z[c];
                   c++;
                   r=1;

                break;
            }
        }

    int aa=0,bb=0,cc=0;
    for(int i=0;i<n;i++)
        {
           aa+=x[i];
           bb+=y[i];
           cc+=z[i];
        }

    if(aa==0 & bb==0 & cc==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }



    return 0;
}
