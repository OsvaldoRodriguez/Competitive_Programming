#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
const int N =100005;
int v[110];
int main()
{
  int n,m;
  cin>>n>>m;
  int ans=0;
  for(int i=0;i<=101;i++){
    for(int j=0;j<=101;j++){
      if(i*i+j==n && i+j*j==m)
        ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
