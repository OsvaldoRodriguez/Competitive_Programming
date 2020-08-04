#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N= 9;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
bool v[26];
int main(){
  /*ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);*/
  ll r1,r2;
  int t;
  cin>>t;
  while(t--){
    cin>>r1>>r2;
    if(r1*r1>2*r2*r2)
      cout<<1<<'\n';
      else cout<<2<<'\n';

  }
  return 0;
}
