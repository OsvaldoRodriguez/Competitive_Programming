#include <bits/stdc++.h>
using namespace std;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
typedef long long ll;
const int N= 201;
int v[4*N+5];
int main(){
  int t,n,cn;
  scanf("%d",&t );
  while(t--){
    scanf("%d",&n);
    cn=n*4;
    for(int i=0;i<cn;i++)
      scanf("%d",&v[i]);
    sort(v,v+cn);
    int area=v[0]*v[cn-1];
    int area1=v[1]*v[cn-2];
    bool flag=1;
    for(int i=2;i<cn;i+=2){
      int a=v[i]*v[cn-i-1];
      int b=v[i+1]*v[cn-i-2];
      if(v[i]!=v[i+1]|| v[cn-i-1]!=v[cn-i-2] || a!=area || a!=area1 || b!=area || b!=area1){
        printf("NO\n");
        flag=0;
        break;
      }
    }
    if(flag)
    printf("YES\n");
  }
  return 0;
}
