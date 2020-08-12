#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 10010;
int vuelta(int n){
  int nn=0,p=1;
  while(n>0){
    nn=nn*10+(n%10);
    n/=10;
  }
  return nn;
}
int main()
{
  int t,n,m;
  cin>>t;
  while(t--){
    cin>>n>>m;
    cout<<vuelta(vuelta(n)+vuelta(m))<<endl;
 
  }
  return 0;
}
