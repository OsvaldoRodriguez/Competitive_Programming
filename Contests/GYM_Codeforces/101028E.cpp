#include <bits/stdc++.h>
using namespace std;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
typedef long long ll;
const int N= 1001;
int v[N];
int GCD(int a,int b){
  if(b==0)return a;
  return GCD(b,a%b);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t,n,m,q,a1,a2,b1,b2;
  char a;
  cin>>t;
  int  div,ans;
  while(t--){
    cin>>n;
    ans=0;
    for(int i=0;i<n;i++)
      cin>>v[i];
    div=v[0];
    for(int i=1;i<n;i++)
      div=GCD(div,v[i]);
    for(int i=0;i<n;i++)
      ans+=v[i]/div;
    cout<<div<<" "<<ans<<"\n";
  }
  return 0;
}
