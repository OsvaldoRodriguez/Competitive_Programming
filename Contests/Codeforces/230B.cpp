#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =1000001;
set<ll> s;
int v[N];
int main(){
  v[0]=v[1]=1;
  for(ll i=2;i<N;i++){
    if(!v[i]){
      s.insert(i*i);
      for(ll j=i+i;j<N;j+=i)
        v[j]=1;
    }
  }
  int n;
  ll x;
  cin>>n;
  int ans=0;
  for(int i=0;i<n;i++){
    cin>>x;
    if(s.count(x))
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
  return 0;
}
