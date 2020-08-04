#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,m,k;
  while(cin>>n>>m>>k)
    if(m>=n && k>=n)
      cout<<"Yes\n";
    else
      cout<<"No\n";
  return 0;
}
