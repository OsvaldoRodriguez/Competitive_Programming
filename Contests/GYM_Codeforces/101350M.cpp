#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 100005;
map<string,double> m1;
int main(){
  int t,n,m;
  double x;
  char s[20];
  char key[]="JD";
  scanf("%d",&t);
  while(t--){
    m1.clear();
    scanf("%d %d",&n,&m );
    while(n--){
      scanf("%s %lf",&s,&x);
      m1[s]=x;
    }
    double ans=0;
    while(m--){
      scanf("%lf %s",&x,&s);
      if(strcmp(s,key)==0)
        ans+=x;
      else ans+=m1[s]*x;
    }
    printf("%.6lf\n",ans );
  }
  return 0;
}
