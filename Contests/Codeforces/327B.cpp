#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 10000001;
bool v[N];
int GCD(int a,int b){
  if(!b)return a;
  return GCD(b,a%b);
}
int LCM(int a,int b){
  return a*(b/GCD(a,b));
}
bool potencia(ll x){
  if((x&(x-1))==0)
    return 1;
  return 0;
}
int main()
{
  int n;
  v[0]=v[1]=1;
  for(int i=2;i*i<N;i++)
    if(!v[i])
      for(int j=i*i;j<N;j+=i)
        v[j]=1;
  cin>>n;
  int ans=0;
  for(int i=2;ans<n;i++)
    if(!v[i]){
      cout<<i<<" ";
      ans++;
    }
  cout<<endl;

  return 0;
}
