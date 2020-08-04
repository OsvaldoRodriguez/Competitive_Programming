#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 1e5+10;
int main(){
  int t,a,b;
  ll d;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d %lld",&a,&b,&d);
    double d1=d;
    //printf("%.6lf\n",d1);
    printf("%.6lf\n",(d1*d1)/2 );
  }
  return 0;
}

