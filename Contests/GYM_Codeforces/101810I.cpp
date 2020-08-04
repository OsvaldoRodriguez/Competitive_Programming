#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2005;
map<int,int> m1;
int main(){

  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);
  int t,n,cn,m;
  cin>>t;
  while(t--){
    m1.clear();
    cin>>n>>m;
    if(m>n){
      cout<<"-1\n";
      continue;
    }
    if(n%m==0){
      for(int i=0;i<m;i++)
        cout<<n/m<<" ";
      cout<<"\n";
      continue;
    }
    cn=n;
    m1[n/m]=m-n%m;
    n=n-(m-(n%m))*(n/m);
    m=cn%m;
    m1[n/m]=m-n%m;
    for(auto i=m1.begin();i!=m1.end();i++){
      for(int j=0;j<i->second;j++)
        cout<<i->first<<" ";
    }
    cout<<"\n";
  }

  return 0;
}
