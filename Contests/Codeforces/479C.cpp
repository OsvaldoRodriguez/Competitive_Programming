#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =5005;
typedef pair<int,int> ii;
ii v[N];
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>v[i].first>>v[i].second;
  sort(v,v+n);
  int ans=-1;
  for(int i=0;i<n;i++)
    if(ans<=v[i].second)
      ans=v[i].second;
    else
      ans=v[i].first;
  cout<<ans<<endl;
  return 0;
}
