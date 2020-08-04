#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1005;
bool v[N];
int main()
{
  int n,m,x,y,raiz;
  while(cin>>n>>m){
    memset(v,0,sizeof v);
    while(m--){
      cin>>x>>y;
      v[x]=v[y]=1;
    }
    raiz=-1;
    for(int i=1;i<=n;i++)
      if(!v[i]){
        raiz=i;
        break;
      }
    cout<<n-1<<endl;
    int i=1;
    if(raiz==i)
      i++;
    for(;i<=n;i++){
      if(raiz!=i)
      cout<<raiz<<" "<<i<<endl;
    }
  }
  return 0;
}
