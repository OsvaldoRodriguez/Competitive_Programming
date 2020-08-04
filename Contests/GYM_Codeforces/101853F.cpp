#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 1e4+5;
vector<int> v1;
int main(){
  int t,n,m,ans;
  char a[10],b[10];
  scanf("%d",&t);
  while(t--){
    scanf("%d %d",&n,&m);
    m*=3600;
    ans=0;
    while(n--){
      scanf("%s %s",&a,&b);
      int hi=(a[0]-'0')*10+(a[1]-'0');
      int mi=(a[3]-'0')*10+(a[4]-'0');
      int hf=(b[0]-'0')*10+(b[1]-'0');
      int mf=(b[3]-'0')*10+(b[4]-'0');
      hi*=3600;mi*=60;hf*=3600;mf*=60;
      ans+=hf+mf-(hi+mi);
      //printf("%d %d %d %d %d %d\n",hi,mi,hf,mf,ans,m);
    }
    printf(ans>=m?"YES\n":"NO\n");
  }
  return 0;
}
