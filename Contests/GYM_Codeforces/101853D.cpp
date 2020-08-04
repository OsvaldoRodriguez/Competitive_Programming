#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 1e5+5;
int main(){
  int t,n,x,ans=0;
  scanf("%d",&t );
  while(t--){
    ans=0;
    scanf("%d",&n);
    while(n--){
      scanf("%d",&x);
      if(x!=0)
        ans++;
    }
    printf("%d\n",ans);
  }
  return 0;
}
