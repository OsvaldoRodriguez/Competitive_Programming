#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N =1e5+5;
int v[2*N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;
  if((n&1)){
    n*=2;
    int c1=1,c2=n;
    bool flag=1;
    for(int i=1;i<=n/2;i++){
      if(flag){
        v[i]=c1++;
        v[i+n/2]=c1++;
        flag=0;
      }else{
        flag=1;
        v[i]=c2--;
        v[i+n/2]=c2--;
      }
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
      cout<<v[i]<<" ";
      cout<<"\n";
  }else cout<<"NO\n";
  return 0;
}
