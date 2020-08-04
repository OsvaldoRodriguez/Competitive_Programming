#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 100005;
int main()
{
  string s;
  while(cin>>s){
    int i;
    bool flag=0;
    for(i=0;i<s.size();i++)
      if(s[i]=='0'){
        flag=1;
        break;
      }
      else{
        if(i+1==s.size() && !flag)
          break;
        cout<<s[i];
      }
    i++;
    for(;i<s.size();i++)
      cout<<s[i];
    cout<<endl;
  }
  return 0;
}
