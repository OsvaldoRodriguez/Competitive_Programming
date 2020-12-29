#include <iostream>
using namespace std;
int main()
{
    int n,a,b,c;
    while(scanf("%d",&n )!=EOF)
    {
      a=1,b=1;
      c=n-2;
      while(a%3==0 or c%3==0)
      {
        a++;
        c--;
      }
      printf("%d %d %d\n",a,b,c);


    }


    return 0;
}
