#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1000001;
ll v[N],n,m;
bool f(ll q){
  ll res=0;
  for(int i=0;i<n;i++){
    if(v[i]>q)
      res+=v[i]-q;
  }
  if(res>=m)
    return 1;
  return 0;
}
int main()
{
  ll may=0;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>v[i];
    may=max(may,v[i]);
  }
  ll a=0,b=may,m;
  while(b-a>1)
  {
    m=(a+b)>>1;
    if(f(m))
      a=m;
    else
      b=m;
  }
  cout<<a<<"\n";
  return 0;
}
