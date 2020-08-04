#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,char> ss;
const int N = 200005;
int v[26];
vector<ss> v1;
int main(){
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++)
    v[s[i]-'a']++;
  for(int i=0;i<26;i++){
    if(v[i])
      v1.push_back(ss(v[i],'a'+i));
  }
  sort(v1.begin(),v1.end());
  int ans=0;
  if(v1.size()>2)
  for(int i=0;i<v1.size()-2;i++){
  //  cout<<v1[i].first<<" "<<v1[i].second<<endl;
    ans+=v1[i].first;
  }
  cout<<ans<<endl;

  return 0;
}
