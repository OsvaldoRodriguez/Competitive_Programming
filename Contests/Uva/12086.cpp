#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200002;
int v[N],FT[N],n;
void update(int i,int v)
{
  int idx=i;
  while(idx<=n)
  {
    FT[idx]+=v;
    idx+=idx&(-idx);
  }
}
void crear()
{
  for(int i=1;i<=n;i++)
    update(i,v[i]);
}
ll sum(int i)
{
  int idx=i;
  ll sum=0;
  while(idx>0)
  {
    sum+=FT[idx];
    idx-=idx&(-idx);
  }
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a,b,cont=1;
  string c;
  while(cin>>n && n)
  {
    memset(v,0,sizeof v);
    memset(FT,0,sizeof FT);
    for(int i=1;i<=n;i++)
      cin>>v[i];
    crear();
    if(cont>1)
      cout<<"\n";
    cout<<"Case "<<cont++<<":\n";
    while(true)
    {
      cin>>c;
      if(c=="END")
        break;
      cin>>a>>b;
      if(c=="M")
        cout<<sum(b)-sum(a-1)<<"\n";
      else
      {
        update(a,b-v[a]);
        v[a]=b;//clave para enviar a un juez
      }
    }
  }
  return 0;

}
