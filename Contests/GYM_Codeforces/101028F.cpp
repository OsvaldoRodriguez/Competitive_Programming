#include <bits/stdc++.h>
using namespace std;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
typedef long long ll;
const int N= 1001;
int v[N];
int main(){
  /*ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);*/
  int t,n,m,q,a1,a2,b1,b2;
  cin>>t;
  //char a[1001],b[1001];
  int  div,ans;
  string a,b;
  while(t--){
    cin>>a>>b;
    //scanf("%s %s",&a,&b);
    int tt=a.size();
    bool flag=0;
    for(int i=0;i<tt-4+1;i++){
      //cout<<i<<endl;
      if(a[i]==b[0] && a[i+1]==b[1] && a[i+2]==b[2] && a[i+3]==b[3]){
        flag=1;
        break;
      }
    }
    if(flag){
      cout<<"good\n";
      //printf("good\n" );
      continue;
    }
    flag=0;
    for(int i=0;i<=tt-3 ;i++){
      //cout<<i<<" segunda\n";
      if(i+2==tt)break;
      if(a[i]==b[1] && a[i+1]==b[2] && a[i+2]==b[3]){
        flag=1;
        break;
      }
      if(a[i]==b[0] && a[i+1]==b[2] && a[i+2]==b[3]){
        flag=1;
        break;
      }
      if(a[i]==b[0] && a[i+1]==b[1] && a[i+2]==b[3]){
        flag=1;
        break;
      }
      if(a[i]==b[0] && a[i+1]==b[1] && a[i+2]==b[2]){
        flag=1;
        break;
      }
    }
    if(flag){
      cout<<"almost good\n";
      //printf("almost good\n" );
    }else cout<<"none\n";
  }
  return 0;
}
