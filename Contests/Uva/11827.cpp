#include <bits/stdc++.h>
using namespace std;
int v[101];
int GCD(int a,int b){
  if(b==0)
    return a;
  return GCD(b,a%b);
}
int LCM(int a,int b)
{
  return a/(b*GCD(a,b));
}
int main()
{
  int n,p;
  cin>>n;
  string s,aux;
  cin.ignore();
  while(n--)
  {
    p=0;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
      aux="";
      while(s[i]!=' ' && i!=s.size()){
        aux+=s[i++];
      }
      v[p++]=atoi(aux.data());
    }
    int ans=0;
    for(int i=0;i<p;i++){
      for(int j=i+1;j<p;j++){
        ans=max(ans,GCD(v[i],v[j]));
      }
    }
    cout<<ans<<'\n';

  }
  return 0;
}
