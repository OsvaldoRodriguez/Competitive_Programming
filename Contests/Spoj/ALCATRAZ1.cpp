#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1001;
int v[N];
bool cmp(int a,int b){
  return a>b;
}
int main()
{
  int t,ans=0;
  string s;
  cin>>t;
  while(t--){
    ans=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
      ans+=s[i]-'0';
    cout<<ans<<endl;
  }
 
 
 
  return 0;
}
 
