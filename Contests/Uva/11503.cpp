#include <bits/stdc++.h>
using namespace std;
map<string,int> m;
const int N = 200010;
int p[N],c[N];
int FIND(int a)
{
  if(a==p[a])
    return a;
  return p[a]=FIND(p[a]);
}
int UNION(int a,int b)
{
  int pa=FIND(a),pb=FIND(b);
  if(pa!=pb)
  {
    if(c[pa]>c[pb])
    {
        c[pa]+=c[pb];
        p[pb]=pa;
        return c[pa];
    }
    c[pb]+=c[pa];
    p[pa]=pb;
    return c[pb];
  }
  return c[pa];
}
int main()
{
  int t,n;
  string a,b;
  cin>>t;
  while(t--)
  {
    m.clear();
    cin>>n;
    for(int i=0;i<N;i++)
      p[i]=i,c[i]=1;
    int conj=0;
    int nn=n;
    while(n--)
    {
      cin>>a>>b;
      int a1=m[a],b1=m[b];
      if(a1==0)
        m[a]=++conj,a1=conj;
      if(b1==0)
        m[b]=++conj,b1=conj;

      cout<<UNION(a1,b1)<<"\n";

    }
  }
  return 0;
}
