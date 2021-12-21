#include <bits/stdc++.h>

using namespace std;

void minimo(int x,int y,int z,int n)
{
    int ans=0;
    if(x<y)
        ans=x;
    else
        ans=y;

    if(ans<z)
        cout<<ans/n<<endl;
    else
        cout<<z/n<<endl;
}
int main()
{
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    minimo(k*l/nl,d*c,p/np,n);

    return 0;
}
