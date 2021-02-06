#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t,c=1,p;
  string s;
  cin>>t;
  while(t--){
    cin>>s;
    p=1;
    int i,pun=0;
    for(i=0;i<s.size();i++){
      while(s[i]!=s[i%p] && i<s.size())
        p++;
    }
    if(c>1)
      cout<<"\n";
      c++;
    if(i%p==0)
      cout<<p<<"\n";
    else
      cout<<i<<"\n";
  }
}
