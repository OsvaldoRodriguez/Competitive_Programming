#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
const int N =100005;
int v[5];
int main()
{
  int n,x,y=0,ans=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x;
    if(x==2)
      v[x]+=2;
    else
      v[x]++;
  }
  ans+=v[4]+v[3];
  v[4]=0;
  v[1]-=v[3],v[3]=0;
  if(v[1]<0)
    v[1]=0;
  ans+=v[2]/4;
  v[2]=v[2]%4;
  ans+=v[1]/4,v[1]=v[1]%4;
  if(v[1]+v[2]>4)
    ans+=2;
  else{
    if(v[1]+v[2]>0)
      ans++;
  }
    cout<<ans<<endl;
  return 0;
}
