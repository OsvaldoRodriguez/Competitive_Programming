#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 100001;
int main()
{
  int n;
  while(cin>>n)
  {
    int i=1;
    if((n&1)){
      i=2;
      cout<<(n-3)/2+1<<endl;
    }
    else
      cout<<n/2<<endl;

    for(;i<=n/2 && n!=3;i++)
      cout<<2<<" ";
    if((n&1))
      cout<<3<<" ";
    cout<<endl;
  }

  return 0;
}
