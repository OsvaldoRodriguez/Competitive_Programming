#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =1000001;
int v[26];
int main(){
  string s;
  int k,may=0;
  cin>>s>>k;
  for(int i=0;i<26;i++){
    cin>>v[i];
    may=max(may,v[i]);
  }
  int ans=0;
  for(int i=0;i<s.size();i++){
    ans+=(i+1)*v[s[i]-'a'];
  }
  int n=s.size(),m=n+k;
  ans+=(((m*(m+1))>>1)-((n*(n+1))>>1))*may;
  cout<<ans<<endl;
  return 0;
}
