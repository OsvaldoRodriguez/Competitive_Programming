#include <bits/stdc++.h>
using namespace std;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
typedef long long ll;
const int N= 101;
int v[N];
int main(){
  int n,m,k,q;
  int t;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++)
      scanf("%d",&v[i]);
    bool flag=1;
    for(int i=0;i<n-1;i++){
      q=max(0,v[i+1]-k);
      m+=v[i]-q;
      if(m<0){
        flag=0;break;
      }
    }
    if(flag)printf("yes\n" );
    else printf("no\n" );
  }

  return 0;
}
