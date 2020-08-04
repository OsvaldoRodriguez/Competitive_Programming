#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string,string> ss;
const int N = 200005;
vector<ss> v;
int main(){
  int n;
  string s,a;
  cin>>n;
  cin.ignore();
  while(n--){
    cin>>s>>a;
    v.push_back(ss(a,s));
  }
  sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++)
    cout<<v[i].second<<" "<<v[i].first<<"\n";


  return 0;
}
