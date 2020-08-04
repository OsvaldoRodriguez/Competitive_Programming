#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 200005;
int t,n;
vector<int> v(26,0);
vector<vector<int> > x;
bool f(int m){
  for(int i=0;i<26;i++){
    if(x[m][i]<v[i])return 0;
  }
  return 1;
}
int main()
{
  int t;
  string s;
  cin>>t>>s;
  for(int i=0;i<t;i++){
    v[s[i]-'a']++;
    x.push_back(v);
  }
  cin>>n;
  while(n--){
    cin>>s;
    v.assign(26,0);
    for(int i=0;i<s.size();i++)
      v[s[i]-'a']++;
    int a=-1,b=t+1,m;
    while(b-a>1){
      m=(a+b)>>1;
      if(f(m))
        b=m;
      else
        a=m;
    }
    cout<<++b<<endl;
  }
  return 0;
}
