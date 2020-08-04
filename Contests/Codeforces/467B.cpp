#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =1005;
int v[N];
int main(){
  int n,m,k;
  cin>>n>>m>>k;
  for(int i=0;i<=m;i++)
    cin>>v[i];
  bitset<32> a(v[m]);
  int ans=0;
  for(int i=0;i<m;i++){
    bitset<32> b(v[i]);
    b^=a;
    if(b.count()<=k)
      ans++;
  }
  cout<<ans<<endl;

  return 0;
}
