#include "bits/stdc++.h"
using namespace std;
vector<int> v;
int main()
{
  int n,i=0;
  string s;
  cin>>n>>s;
  for(int i=1;i<=n;i++)
    if(n%i==0)
      v.push_back(i);
  string aux,aux1;

  for(int i=0;i<v.size();i++)
  {
      aux1=s;
      aux=s.erase(0,v[i]);
      s=aux1.erase(v[i],aux1.size()-1);
      reverse(s.begin(),s.end());
      s=s+aux;
  }
  cout<<s<<"\n";
  return 0;
}
