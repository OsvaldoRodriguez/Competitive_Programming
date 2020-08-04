#include <bits/stdc++.h>
using namespace std;
set<int> s;
int main()
{
  int n,x;
  cin>>n;
  while(n--)
  {
    cin>>x;
    if(x!=0)
      s.insert(x);
  }
  cout<<s.size()<<endl;
  return 0;
}
