#include <bits/stdc++.h>
using namespace std;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
typedef long long ll;
const int N= 1001;
int v[N];
int m=1000000007;
int main(){
  /*ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);*/
  int t,n;
  string a,b;
  cin>>t;
  while(t--){
    cin>>n>>a>>b;
    bool flag=1;
    for(int i=0;i<n;i++){
      if(a[i]=='1' && b[i]=='0'){
        flag=0;
        break;
      }
    }
    if(!flag){
      cout<<"IMPOSSIBLE\n";
      continue;
    }
    else {
      ll ans=1;
      for(int i=0;i<n;i++){
        if(a[i]=='1')
          ans=(ans%m*2%m)%m;
      }
      cout<<ans<<"\n";
    }
  }
  return 0;
}
