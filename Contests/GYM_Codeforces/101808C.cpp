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
  int t,mid,ans;
  string a,b;
  cin>>t;
  while(t--){
    memset(v,0,sizeof v);
    memset(w,0,sizeof w);
    ans=0;
    cin>>a>>b;
    string rev=b;
    for(int i=0;i<a.size();i++){
      v[a[i]-'a']++;
      w[b[i]-'a']++;
    }
    reverse(rev.begin(),rev.end());
    //cout<<rev<<endl;
    bool flag=0;
    for(int i=0;i<26;i++){
      if(v[i]!=w[i]){
        flag=1;
        break;
      }
    }
    if(flag)
    {
      cout<<-1<<"\n";
      continue;
    }
    int t=a.size()/2;
    int p1=0,p2=0;
    bool f1=1;
    while(p1<=t && p2<=t){
      if(a[p1]!=b[p1] && f1){
        f1=0;
        ans++;
      }else
      if(!f1 && a[p1]!=rev[p1]){
        f1=1;
        ans++;
      }
      p1++;p2++;

    }
    cout<<ans<<"\n";

  }
  return 0;
}
