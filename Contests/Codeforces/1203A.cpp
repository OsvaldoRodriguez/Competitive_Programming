#include <bits/stdc++.h>
using namespace std;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
typedef long long ll;
const int N= 201;
int v[N],v1[N];
int main(){
  int t,n,id;
  scanf("%d",&t );
  while(t--){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d",&v[i]);
      v1[n-i-1]=v[i];
      if(v[i]==1)
        id=i;
    }
    bool flag=1;
    for(int i=id+1;i<n+id-1;i++){
      //printf("%d %d\n",v[i%n],v[(i+1)%n]);
      if(v[i%n]+1!=v[(i+1)%n]){
        flag=0;break;
      }
    }
    if(flag){
      printf("YES\n" );
      continue;
    }
    flag=1;
    for(int i=id+1;i<n+id-1;i++){
      //printf("%d %d\n",v[i%n],v[(i+1)%n]);
      if(v[i%n]!=v[(i+1)%n]+1){
        flag=0;break;
      }
    }
    if(flag){
      printf("YES\n" );
      continue;
    }
    id=n-id;
    flag=1;
    for(int i=id;i<n+id-2;i++){
      //printf("%d %d\n",v1[i%n],v1[(1+i)%n]);
      if(v1[i%n]!=v1[(i+1)%n]+1){
        flag=0;break;
      }
    }
    if(flag){
      printf("YES\n" );
      continue;
    }

    id=n-id;
    flag=1;
    for(int i=id;i<n+id-2;i++){
      //printf("%d %d\n",v1[i%n],v1[(1+i)%n]);
      if(v1[i%n]+1!=v1[(i+1)%n]){
        flag=0;break;
      }
    }
    if(flag){
      printf("YES\n" );
      continue;
    }
    printf("NO\n");
  }
  return 0;
}
/*
1
7
3 4 1 2 7 5 6
*/
