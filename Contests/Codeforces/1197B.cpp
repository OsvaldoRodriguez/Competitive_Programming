#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =200005;
int v[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  bool fc=1;
  int p=0;
  for(int i=0;i<n-1;i++){
    if(v[i]<v[i+1]){
      p++;
    }else break;
  }
  //cout<<p<<endl;
  for(int i=p;i<n-1;i++){
    if(v[i]>v[i+1]){
      p++;
    }else break;
  }
  //cout<<p<<endl;
  if(p+1==n)cout<<"YES\n";
  else cout<<"NO\n";
  return 0;
}
