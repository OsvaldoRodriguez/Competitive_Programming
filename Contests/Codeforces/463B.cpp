#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 100005;
int v[N],n;
bool f(int q){
  int ans=0;
  v[0]=q;
  for(int i=1;i<=n;i++){
    ans+=v[i-1]-v[i];
    if(ans<0)
      return 0;
  }
  return 1;
}
int main()
{
  cin>>n;
  for (int i = 1; i <=n; i++) {
    cin>>v[i];
  }
  int a=0,b=1e9,m;
  while(b-a>1){

    m=(a+b)>>1;
    //cout<<a<<" "<<m<<" "<<b<<" "<<f(m)<<endl;
    if(f(m))
      b=m;
    else
      a=m;
  }
  cout<<b<<endl;
  return 0;
}
