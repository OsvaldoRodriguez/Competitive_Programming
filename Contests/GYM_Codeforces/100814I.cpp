#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 101;
int v[N];
int main(){
  int t;
  scanf("%d",&t );
  int n;
  while(t--){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      scanf("%d",&v[i]);
    int ans=0;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        ans=max(ans,__builtin_popcount(v[i]^v[j]));
      }
    }
    printf("%d\n",ans );
  }
  return 0;
}
