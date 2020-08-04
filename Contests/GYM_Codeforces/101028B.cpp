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
  string a,b;
  while(t--){
    cin>>a>>b;
    for(int i=0;i<a.size();i++){
      a[i]=tolower(a[i]);
      if(a[i]=='b')
        a[i]='p';
      if(a[i]=='i')
        a[i]='e';
    }
    for(int i=0;i<b.size();i++){
      b[i]=tolower(b[i]);
      if(b[i]=='b')
        b[i]='p';
      if(b[i]=='i')
        b[i]='e';
    }
    if(a==b)
    cout<<"Yes\n";else cout<<"No\n";
  }
  return 0;
}
