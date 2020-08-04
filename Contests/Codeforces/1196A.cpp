#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> il;
typedef pair<ll,int> li;
const int N = 90;
int v[N];
int main(){
  int n;
  ll a,b,c;
  cin>>n;
  while(n--){
    cin>>a>>b>>c;
    ll ans=(a+b+c)/2;
    cout<<ans<<"\n";
  }

  return 0;
}
