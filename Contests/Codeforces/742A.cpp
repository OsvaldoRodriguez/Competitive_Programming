#include <bits/stdc++.h>
using namespace std;
int POW(int a,int b,int m)
{
  if(!b)return 1;
  if(!(b&1))
    return POW((a%m*a%m)%m,b/2,m);
  return (POW((a%m*a%m)%m,b/2,m)*a%m)%m;
}
int main()
{
  int a= 1378;
  int b,m=10;
  while(cin>>b)
    cout<<POW(a,b,m)<<"\n";
    return 0;
}
