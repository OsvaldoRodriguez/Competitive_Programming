#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
int v1[N],v2[N],v3[N];
int main(){
  int n,k,t;
  char s[N];
  char p[]={'R','G','B'};
  scanf("%d\n",&t);
  while(t--){
    scanf("%d %d %s",&n,&k,&s);
    v1[0]=(s[0]!='R');
    v2[0]=(s[0]!='G');
    v3[0]=(s[0]!='B');
    for(int i=1;i<n;i++){
      v1[i]=v1[i-1]+(p[i%3]!=s[i]);
      v2[i]=v2[i-1]+(p[(i+1)%3]!=s[i]);
      v3[i]=v3[i-1]+(p[(i+2)%3]!=s[i]);
    }
    int ans=min(v1[k-1],min(v2[k-1],v3[k-1]));
    for(int i=1;i<n-k+1;i++){
      ans=min(ans,v1[i+k-1]-v1[i-1]);
      ans=min(ans,v2[i+k-1]-v2[i-1]);
      ans=min(ans,v3[i+k-1]-v3[i-1]);
    }
    printf("%d\n",ans);
  }
  return 0;
}
