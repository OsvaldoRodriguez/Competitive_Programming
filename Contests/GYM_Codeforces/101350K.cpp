#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 100005;
typedef vector<int> vi;
int main(){
  int t;
  ll a,b,n;
  scanf("%d",&t );
  while(t--){
    vi sol(10,-1);
    scanf("%lld %lld %lld",&a,&b,&n);
    for(int i=1;1;i++){
      ll y=a*i*i+b*i;
      //cout<<y<<" ngera\n";
      if(y>n)break;
      vi aux(10,-1);
      while(y>0){
        aux[y%10]++;
        y/=10;
      }
      int hh=-1;
      for(int i=0;i<10;i++)
        hh=max(hh,aux[i]);

      for(int i=0;i<10;i++)
        if(hh==aux[i]){
          sol[i]++;
        }
    }
    int hh=-1;
    for(int i=0;i<10;i++){
      hh=max(hh,sol[i]);
    }
    int ans=-1;
    for(int i=0;i<10;i++){
      if(hh==sol[i] && sol[i]!=-1){
        ans=i;
        break;
      }
    }
    printf("%d\n",ans );
  }
  return 0;
}
