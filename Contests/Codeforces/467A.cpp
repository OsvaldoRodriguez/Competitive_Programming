#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
const int N =100000000;
vector<int> v;
int main()
{
  int n,x,y,ans=0;
  cin>>n;
  while(n--){
    cin>>x>>y;
    if(y-x>=2)
      ans++;
  }
  cout<<ans<<endl;
  return 0;
}
