#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 1000;
int main(){
  int t;
  scanf("%d",&t );
  int h,n;
  while(t--){
    scanf("%d %d", &n,&h);
    if(n==h)printf("Square\n" );
    else printf("Rectangle\n" );
  }
  return 0;
}
