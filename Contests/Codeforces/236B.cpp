#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
const int N =100005;
int v[N];
int div(int n){
  int ans=0;
  int i=1;
  for(;i*i<n;i++){
    if(n%i==0)
      ans+=2;
  }
  if(i*i==n)
    ans++;
  return ans;
}
int main()
{
  int v[3];
  cin>>v[0]>>v[1]>>v[2];
  ll ans=0;
  ll m=(1<<30);
  for(int i=1;i<=v[0];i++){
    for(int j=1;j<=v[1];j++){
      for(int k=1;k<=v[2];k++){
        ans=(ans%m+div(i*j*k)%m)%m;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
