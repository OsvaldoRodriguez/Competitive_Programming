#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> v;
int main(){
  int t,n,m;
  cin>>t;
  string s;
  while(t--){
    v.clear();
    cin>>n>>m;
    for(int i=0;i<n;i++){
      cin>>s;
      v.push_back(s);
    }
    vector<int> r(n),c(m);
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(v[i][j]=='.'){
          r[i]++;
          c[j]++;
        }
      }
    }
    int ans=(1<<30);
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(v[i][j]=='.')
          ans=min(ans,c[j]+r[i]-1);
        else
          ans=min(ans,c[j]+r[i]);
      }
    }
    cout<<ans<<endl;

  }
  return 0;
}
