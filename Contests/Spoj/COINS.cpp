#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10000001;
map<int,ll > m;
ll maxi(ll a,ll b){
  if(a>b)
    return a;
  return b;
}
ll f(int n){
  if(n==0)return 0;
  if(m[n]!=0)return m[n];
  return m[n]=maxi(n,f(n/2)+f(n/3)+f(n/4));
}
int main()
{
  int n;
  while(cin>>n){
    cout<<f(n)<<endl;
  }
  return 0;
}
