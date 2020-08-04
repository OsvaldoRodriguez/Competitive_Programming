#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 100001;
// 2 4
int main()
{
  int n;
  double x,sum=0;
  cin>>n;
  double n1=n;
  while(n--){
    cin>>x;
    sum+=x;
  }
  double ans=sum/(n1*100.0)*100.0;
  printf("%.12lf\n",ans);
  return 0;
}
