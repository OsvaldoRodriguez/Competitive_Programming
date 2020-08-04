#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 1e4+5;
int v[N];
vector<int> v1;
int main(){
  int t,n,x;
  scanf("%d",&t );
  while(t--){
    memset(v,0,sizeof v);
    v1.clear();
    int ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d",&x);
      v[x]++;
    }
    for(int i=1;i<N;i++)
      if(v[i]){
        v1.push_back(i);
        if(ans<v[i])
          ans=v[i];
      }
    if((int)v1.size()==1){
      printf("%d\n",v[v1[0]]);
      continue;
    }
    for(int i=1;i<v1.size();i++)
      if(abs(v1[i]-v1[i-1])<=1)
      ans=max(ans,v[v1[i]]+v[v1[i-1]]);
    printf("%d\n",ans);

  }
  return 0;
}

