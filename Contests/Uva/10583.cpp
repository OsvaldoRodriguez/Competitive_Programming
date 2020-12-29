#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int p[N],n;
int FIND(int a)
{
  if(a==p[a])
    return a;
  return p[a]=FIND(p[a]);
}
void UNION(int a ,int b)
{
  int pa=FIND(a),pb=FIND(b);
  if(pa!=pb)
  {
    p[pa]=pb;
    n--;
  }
}
int main()
{
  int m,a,b,c=1;
  while(scanf("%d %d",&n,&m )!=EOF && n && m)
  {
    for(int i=0;i<N;i++)
      p[i]=i;
    while(m--)
    {
      scanf("%d%d",&a,&b );
      UNION(a,b);
    }
    printf("Case %d: %d\n",c++,n );
  }
  return 0;
}
