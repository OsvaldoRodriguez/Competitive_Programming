#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =100005;
typedef pair<string,string> si;
map<string,si> m1;
int main(){
  int n,m;
  string a,b;
  cin>>n>>m;
  while(m--){
    cin>>a>>b;
    m1[a]=si(a,b);
    m1[b]=si(a,b);
  }
  while(n--){
    cin>>a;
    si top=m1[a];
    if((top.first).size()<=(top.second).size())
      cout<<top.first<<" ";
    else
      cout<<top.second<<" ";
  }
  return 0;
}
