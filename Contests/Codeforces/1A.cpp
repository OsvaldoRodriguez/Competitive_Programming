#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
const int N =100000000;
vector<int> v;
int main()
{
  ll n,m,a,ans=0;
  while(cin>>n>>m>>a){
    ll a1=n/a;
    if(n%a!=0)
      a1++;
    ll b1=m/a;
    if(m%a!=0)
      b1++;
    cout<<a1*b1<<endl;
  }
  return 0;
}
