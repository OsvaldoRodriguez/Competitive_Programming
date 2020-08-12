#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 100010;
int n,m,p[N],c[N];
int FIND(int a){return a==p[a]?a:p[a]=FIND(p[a]);}
void UNION(int a,int b){
  a=FIND(a);b=FIND(b);
  if(a!=b &&  c[a]+c[b]<=m){
    p[a]=b;
    c[b]+=c[a];
  }
}
int main()
{
  int q,x,y;
  cin>>n>>m>>q;
  string s;
  for(int i=0;i<=n;i++)
    p[i]=i,c[i]=1;
  while(q--){
    cin>>s>>x;
    if(s=="S")
      cout<<c[FIND(x)]<<"\n";
    else{
      cin>>y;
      if(s=="A")
        UNION(x,y);
      else
        if(FIND(y)==FIND(x))
          cout<<"Yes\n";
        else
          cout<<"No\n";
    }
  }
 
  return 0;
}
