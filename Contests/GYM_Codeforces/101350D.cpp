#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 100005;
int v[N];
int main(){
  int t,n;
  scanf("%d",&t );
  while(t--){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      scanf("%d",&v[i]);
    bool flag=1;
    int a=v[0];
    for(int i=1;i<n;i++){
      if(((a&1) && !(v[i]&1))or (!(a&1) && (v[i]&1))){
        flag=0;
        break;
      }
    }
    if(flag)
    printf("yes\n");
    else printf("no\n" );
  }
  return 0;
}
