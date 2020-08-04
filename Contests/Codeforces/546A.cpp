#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1000001;
int GCD(int a,int b){
  if(!b)return a;
  return GCD(b,a%b);
}
int LCM(int a,int b){
  return a*(b/GCD(a,b));
}
int main()
{
  int k,n,w;
  cin>>k>>n>>w;
  int ans=k*(((w+1)*w)>>1)-n;
  if(ans<0)
    cout<<0;
  else
    cout<<ans;
  cout<<endl;

  return 0;
}
