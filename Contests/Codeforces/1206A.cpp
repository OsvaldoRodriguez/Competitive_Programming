#include <bits/stdc++.h>
#define ll long long
#define N  110
using namespace std;
int v[N],w[N];
set<int> s1,s2;
int main(){
  int n,m;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>v[i];
    s1.insert(v[i]);
  }
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>w[i];
    s2.insert(w[i]);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int ans=v[i]+w[j];
      if(s1.count(ans)==0 && s2.count(ans)==0){
        cout<<v[i]<<" "<<w[j]<<"\n";
        i=n;
        break;
      }
    }
  }
  return 0;
}
