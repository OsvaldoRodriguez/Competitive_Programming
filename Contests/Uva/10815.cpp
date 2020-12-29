#include <bits/stdc++.h>
using namespace std;
set<string> st;
int main()
{
  string s,aux;
  s.clear();
  while(cin>>s){
    for(int i=0;i<s.size();i++)
    {
      aux="";
      s[i]=tolower(s[i]);
      while(s[i]>='a' and s[i]<='z' and i!=s.size())
      {
        aux+=s[i++];
        s[i]=tolower(s[i]);
      }
      //cout<<aux<<endl;
      if(aux!="")
        st.insert(aux);
    }
  }
  for(set<string>::iterator i=st.begin();i!=st.end();i++)
    cout<<*i<<'\n';


  return 0;

}
