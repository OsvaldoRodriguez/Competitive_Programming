#include <bits/stdc++.h>
using namespace std;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
typedef long long ll;
const int N= 200005;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t,n,r,x,ans;
  cin>>t;
  while(t--){
    ans=0;
    cin>>n>>r;
    for(int i=0;i<n;i++){
      cin>>x;
      ans+=x;
    }
    if(ans+1500==r)
    cout<<"Correct\n";else cout<<"Bug\n";
  }

  return 0;
}
