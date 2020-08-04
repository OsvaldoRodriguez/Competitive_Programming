#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N =10000001;
int main()
{
  int n,m,ans;
  while(cin>>n>>m){
    ans=0;
    while(n>0){
      n/=m;ans++;
    }
    if(ans!=0)
      cout<<ans<<"\n";
    else
      cout<<"1\n";
  }
  return 0;
}
