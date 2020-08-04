#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N= 100005;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
int v[N],w[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t,l1,r1,p1,est1,l2,r2,p2,est2,k,tt;
  cin>>t;
  int ans=0;
  while(t--){
    tt=0;
    ans=0;
    cin>>l1>>r1>>p1>>est1;
    cin>>l2>>r2>>p2>>est2>>k;
    while(tt<=k){
      tt++;
      //cout<<p1<<" avanza "<<p2<<endl;
      if(p1==p2){
        //cout<<p1<<" "<<p2<<endl;
        ans++;
      }
      if(est1){
        if(p1+1>r1){
          est1=0;
          p1--;
        }else p1++;
      }else if(p1-1<l1){
        est1=1;
        p1++;
      }else p1--;

      if(est2){
        if(p2+1>r2){
          est2=0;
          p2--;
        }else p2++;
      }else if(p2-1<l2){
        est2=1;
        p2++;
      }else p2--;
    }
    cout<<ans<<"\n";

  }
  return 0;
}
