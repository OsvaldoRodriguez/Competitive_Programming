#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
const int N =100005;
int v[5];
int main()
{
  int n,ans;
  while(cin>>n){
    ans=0;
    ans+=n/5;
    if(n%5!=0)
      ans++;
    cout<<ans<<endl;
  }
  return 0;
}
