#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> il;
typedef pair<ll,int> li;
const int N = 200005;
int v[N];
vector<int> v1;
int main(){
  int n,t,k,cont;
  cin>>t;
  while(t--){
    cont=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
      cin>>v[i];
      if((v[i]&1))
        cont++;
    }
    v1.clear();
    if(cont>=k && (((k&1) && (cont&1)) || (!(k&1) && !(cont&1)))){
      cout<<"YES\n";
      for(int i=0,j=0;j<k;i++)
        if((v[i]&1)){
          if(j+1==k)cout<<n<<" ";
          else
          cout<<i+1<<" ";
          j++;
        }
      cout<<"\n";
    }
    else
      cout<<"NO\n";
  }

  return 0;
}
