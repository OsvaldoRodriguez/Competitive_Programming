#include <bits/stdc++.h>
using namespace std;
const int N =100002;
int ST[N*4+10];
void crear(int nodo,int a,int b)
{
  if(a==b)
  {
    cin>>ST[nodo];
    return ;
  }
  int m=(a+b)>>1;
  crear(nodo*2,a,m);
  crear(nodo*2+1,m+1,b);
  ST[nodo]=min(ST[nodo*2],ST[nodo*2+1]);
}
void update(int nodo,int a,int b,int i,int v)
{
  if(a==b && v==a)
  {
    ST[nodo]=v;
    return ;
  }
  int m=(a+b)>>1;
  if(i<=m)
    update(nodo*2,a,m,i,v);
  else
    update(nodo*2+1,m+1,b,i,v);
  ST[nodo]=min(ST[nodo*2],ST[nodo*2+1]);
}
int query(int nodo,int a,int b,int i,int j)
{
  if(a==i and b==j)
    return ST[nodo];
  int m=(a+b)>>1;
  if(j<=m)
    return query(nodo*2,a,m,i,j);
  if(i>m)
    return query(nodo*2+1,m+1,b,i,j);
  return min(query(nodo*2,a,m,i,m),query(nodo*2+1,m+1,b,m+1,j));
}
int main()
{
  int n,m,a,b;
  cin>>n;
  crear(1,0,n-1);
  cin>>m;
  while(m--)
  {
    cin>>a>>b;
    cout<<query(1,0,n-1,a,b)<<'\n';
  }
    return 0;
}
