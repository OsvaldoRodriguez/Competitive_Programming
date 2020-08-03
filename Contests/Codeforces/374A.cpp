#include <bits/stdc++.h>

using namespace std;
int a,b,inf=10000000;
int pasos(int x1,int y1,int x2,int y2)
{
    if(x1==x2 && y1==y2)
        return 0;
    int d1=abs(x1-x2);
    int d2=abs(y1-y2);
    if(d1%a==0 && d2%b==0 && (d1/a)%2==(d2/b)%2)
        return max((d1/a),(d2/b));
    return inf;
}
int main()
{
    int res=inf,x,y,n,m;
    cin>>n>>m>>x>>y>>a>>b;
    res=min(res,min(pasos(x,y,1,1),min(pasos(x,y,1,m),min(pasos(x,y,n,1),pasos(x,y,n,m)))));
    if(res==inf || ((x+a>n && x-a<1) || (y+b)>m  && y-b<1) and res!=0)
        cout<<"Poor Inna and pony!\n";
    else
        cout<<res<<"\n";
    return 0;
}
