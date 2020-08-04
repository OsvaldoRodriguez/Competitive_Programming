#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N=100005;
int ans=0;
int v[]={4,0,3,3,2,3,4,1,5,4};
/*
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
int t;
int n, k;
*/
int main(){
  int t,n,sum;
  char s[N];
  scanf("%d",&t);
  while(t--){
    bool flag=0;
    int cont=0;
    scanf("%d %s",&n,&s);
    sum=0;
    for(int i=0;i<n;i++){
      sum+=v[s[i]-'0'];
      if(s[i]=='8')
        cont++;
    }
    if(cont==n){
      printf("%s\n",s);
      continue;
    }
    for(int i=0;i<n;i++){
      if(i+1!=n)
      for(int j=9;j>=0;j--){
        if(sum>=v[j]){
          printf("%c",char(j)+'0');
          sum-=v[j];break;
        }
      }else {
        for(int j=9;j>=0;j--)
          if(sum==v[j]){
            printf("%c",char(j)+'0');
            break;
          }
      }
    }
    printf("\n" );
  }
  return 0;
}
/*
.......A
SSS.SSSS
........
........
........
........
........
M.......

*/
