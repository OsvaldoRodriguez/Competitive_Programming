#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N= 9;
int ans=0;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
int t;
int main(){
  cin>>t;
  while(t--){
    ll num;
    cin>>num;
    ll res=num/5;
    if(num%5!=0) res++;
    cout<<res<<endl;
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
