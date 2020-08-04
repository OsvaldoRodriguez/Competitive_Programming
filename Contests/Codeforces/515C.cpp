#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 100005;
map<char,string> m;
int main()
{
  m['2']="2";m['3']="3";m['4']="322";m['5']="5";m['6']="53";
  m['7']="7";m['8']="7222";m['9']="7332";
  int n;
  string s,ans="";
  cin>>n>>s;
  for(int i=0;i<n;i++)
    if(s[i]!='1' and s[i]!='0')
      ans=ans+ m[s[i]];
  sort(ans.rbegin(),ans.rend());
  cout<<ans<<endl;
}
