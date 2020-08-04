#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2005;
map<int,int> m1;
int main(){

  int t,n,m;
  cin>>t;
  while(t--){
    cin>>n;
    m=n-1;
    cout<<__builtin_popcount(m^n)<<"\n";
  }
  return 0;
}
