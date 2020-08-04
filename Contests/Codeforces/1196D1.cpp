#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> il;
typedef pair<ll,int> li;
const int N = 200005;
string v="RGB";
int k,n;
int f(int x,string s,int j){
  int ans=0,c=j;
  for(int i=x;i<k+x;i++)
    if(v[(c++)%3]!=s[i])
      ans++;
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  string s;
  cin>>t;
  int ans,cont;
  while(t--){
    ans=(1<<30);
    cin>>n>>k>>s;
    s=s+s;
    for(int i=0;i<n-k+1;i++){
      cont=f(i,s,0);
      ans=min(ans,cont);
      cont=f(i,s,1);
      ans=min(ans,cont);
      cont=f(i,s,2);
      ans=min(ans,cont);
    }
    cout<<ans<<"\n";
  }
  return 0;
}
