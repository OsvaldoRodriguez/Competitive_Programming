#include <bits/stdc++.h>
using namespace std;
int n;
int v[55][55];
void floyd(){
  for(int k=0;k<n;k++){
    for (int i = 0; i < n; i++) {
      for(int j=0;j<n;j++){
        v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
      }
    }
  }
}
int main()
{
  int t,q,a,b,ans,test=1;
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        scanf("%d",&v[i][j]);
    floyd();
    scanf("%d",&q );
    ans=0;
    while(q--){
      scanf("%d%d",&a,&b);
      a--;b--;
      ans+=v[a][b];
    }
 
    printf("Case #%d: %d\n",test++,ans );
  }
  return 0;
}
