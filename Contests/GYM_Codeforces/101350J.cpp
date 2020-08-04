#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 100005;
int main(){
  int t,r,an;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d",&r,&an );
    double h=sqrt(2*r*r*(1-cos(an*acos(-1)/180.0)));
    double s=(2*r+h)/2.0;
    double At=sqrt(s*(s-r)*(s-r)*(s-h));
    double A=an*acos(-1)*r*r/360;
    printf("%.6lf\n",A-At );
  }
  return 0;
}
