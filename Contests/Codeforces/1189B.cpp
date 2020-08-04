#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> il;
const int N= 100005;
int v[N];
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>v[i];
  sort(v,v+n);
  swap(v[n-2],v[n-1]);
  bool flag=0;
  if(v[n-1]<v[n-2]+v[0] && v[n-2]<v[n-1]+v[n-3])
    flag=1;
  if(flag){
    cout<<"YES\n";
    for(int i=0;i<n;i++)
      cout<<v[i]<<" ";
      cout<<"\n";
  }
  else cout<<"NO\n";
  return 0;
}
/*
6
0 1 2 100 1000 901
*/
