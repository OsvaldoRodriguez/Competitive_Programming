#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int ST[4*N+10];
int f(int x)
{
  if(x==0)return x;
  return x/abs(x);
}
void crear(int nodo,int a,int b)
{
  if(a==b)
  {
    cin>>ST[nodo];
    ST[nodo]=f(ST[nodo]);
    return ;
  }
  int m=(a+b)>>1;
  crear(nodo*2,a,m);
  crear(nodo*2+1,m+1,b);
  ST[nodo]=ST[nodo*2]*ST[nodo*2+1];
}
void update(int nodo,int a,int b,int i,int v)
{
  if(a==b)
  {
    ST[nodo]=v;
    return ;
  }
  int m=(a+b)>>1;
  if(i<=m)
    update(nodo*2,a,m,i,v);
  else
    update(nodo*2+1,m+1,b,i,v);
  ST[nodo]=ST[nodo*2]*ST[nodo*2+1];
}
int query(int nodo,int a,int b,int i,int j)
{
  if(a==i && b==j)
    return ST[nodo];
  int m=(a+b)>>1;
  if(j<=m)
    return query(nodo*2,a,m,i,j);
  if(i>m)
    return query(nodo*2+1,m+1,b,i,j);
  return query(nodo*2,a,m,i,m)*query(nodo*2+1,m+1,b,m+1,j);
}
int main()
{
  string a;
  int x,y,n,m;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while(cin>>n>>m)
  {
    crear(1,1,n);
    while(m--){
    cin>>a>>x>>y;

    if(a=="C")
      update(1,1,n,x,f(y));
    else
    {
      int ans=query(1,1,n,x,y);
      if(ans==0)
        cout<<'0';
      else{
        if(ans==1)
          cout<<'+';
        else
          cout<<'-';
      }
    }
  }
  cout<<'\n';
  }

  return 0;

}
