#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void fact(ll n){
  int c=0;
  while(n%2==0){
    c++;
    n/=2;
  }
  if(c>0)
    cout<<"2^"<<c<<" ";
  c=0;
  for(ll i=3;i*i<=n;i+=2)
  {
    while(n%i==0){
      c++;
      n/=i;
    }
    if(c>0)
      cout<<i<<"^"<<c<<" ";
    c=0;
  }
  if(n>2)
    cout<<n<<"^1";
  cout<<'\n';
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  int c;
  while(cin>>n && n){
    fact(n);
  }
 
}
