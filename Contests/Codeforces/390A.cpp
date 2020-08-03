#include <iostream>
using namespace std;
int dx[101],dy[101];
int main()
{
    int n,x,y;
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        dx[x]=1;
        dy[y]=1;
    }
    int res1=0,res2=0;
    for(int i=0;i<101;i++)
    {
        if(dx[i])
            res1++;
        if(dy[i])
            res2++;
    }
    cout<<min(res1,res2)<<"\n";
    return 0;
}
