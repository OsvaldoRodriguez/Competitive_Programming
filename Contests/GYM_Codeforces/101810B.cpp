#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
vector<ll> v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  ll c,n;
  cin>>t;
  while(t--){
    v.clear();
    cin>>n>>c;
    if(c==1){
        cout<<n<<'\n';
        continue;
    }
    if(n>c){
      ll n1=n-c;
      ll r=n1/(c-1);
      ll nb=r*(c-1);
      ll a=n1-nb;
      v.push_back(1+((r+1)/2));
      for(int i=0;i<c-2;i++)
        v.push_back(1+r);
      v.push_back(1+(r/2));
      if((r+1)%2==0){
        for(ll i=1;i<=a;i++)
          v[i]++;
      }else{
        ll i=v.size()-2,j=0;
        while(j<a){
          j++;
          v[i]++;
          i--;
        }
      }
      for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    }else
      for(int i=1;i<=c;i++)
        if(i<=n)
          cout<<1<<" ";
        else
          cout<<"0 ";
    cout<<"\n";
  }
  return 0;
}
