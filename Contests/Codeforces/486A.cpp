#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 100005;
map<char,string> m;
int main()
{

  ll n,pi,pp;
  while(cin>>n){//4
  pi=pp=n/2;
  if((n&1))
    pi++;
  cout<<-pi*pi+pp*(pp+1)<<endl;
}
  return 0;
}
