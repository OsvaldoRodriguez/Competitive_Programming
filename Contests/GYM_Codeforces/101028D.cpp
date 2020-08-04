#include <bits/stdc++.h>
using namespace std;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
typedef long long ll;
const int N= 101;
char v[N][N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t,n,m,q,a1,a2,b1,b2;
  char a;
  cin>>t;
  while(t--){
    cin>>n>>m>>q;
    memset(v,'.',sizeof v);
    while(q--){
      cin>>a1>>b1>>a2>>b2>>a;
      a1--;b1--;a2--;b2--;
      for(int i=a1;i<=a2;i++)
        for(int j=b1;j<=b2;j++)
          v[i][j]=a;
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cout<<v[i][j];
      }cout<<"\n";
    }
  }
  return 0;
}
