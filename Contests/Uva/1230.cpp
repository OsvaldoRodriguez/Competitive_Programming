#include <bits/stdc++.h>
using namespace std;
int POW(int a,int b,int m )
{
  if(b==0)
    return 1;
  if((b&1)==0)
    return POW((a%m*a%m),b/2,m);
  return (POW((a%m*a%m),b/2,m)*a%m)%m;
}
int main()
{

  int t,a,b,m;
  scanf("%d",&t );
  while(t--)
  {
    scanf("%d %d %d",&a,&b,&m );
    printf("%d\n",POW(a,b,m));
  }
  scanf("%d",&a );

  return 0;

}
