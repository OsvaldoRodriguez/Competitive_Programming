#include "bits/stdc++.h"
using namespace std;
map<char,int> m;
const int N=105;
int v[N][N];
int main()
{
  int n,ans;
  string s;

  while(cin>>n)
  {
    ans=0;
    m.clear();
    while(n--)
    {
      cin>>s;
      m[s[0]]++;
    }
    for(auto i=m.begin();i!=m.end();i++){
      if(i->second>1)
      {
        int j=i->second/2;
        int k=i->second-j;
        ans+=(j*(j-1)/2)+(k*(k-1)/2);
      }

    }
    cout<<ans<<"\n";


  }
}
