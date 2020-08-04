#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N= 9;
int ans=0;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
int t;
int n, k;
string s;
int main(){
  cin>>t;
  while(t--){
    cin>>n>>k;
    k++;
    cin>>s;
    s+="1";
    int cont=0;
    bool sw=false;
    for(int i=0; i<=n; i++){

      if(s[i]=='0'){
        cont++;
      }
      else{
        //cout<<k<<endl;
        if(cont>=k){
          sw=true;
          break;
        }
        else cont=0;
      }
    }
    if(sw) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
  return 0;
}
/*
.......A
SSS.SSSS
........
........
........
........
........
M.......

*/
