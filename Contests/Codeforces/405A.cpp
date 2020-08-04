#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> il;
typedef pair<ll,int> li;
int v[105];
int main(){
  int n,x;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x;
    v[x]++;
  }
  for(int i=0;i<101;i++){
    if(v[i])
      while(v[i]--)
        cout<<i<<" ";
  }
  return 0;
}
