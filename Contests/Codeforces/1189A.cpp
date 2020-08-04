#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> il;
const int N= 105;
int acc1[N],acc0[N];
int main(){
  int n;
  string s;
  cin>>n;
  cin>>s;
  acc1[0]=(s[0]=='1');
  acc0[0]=(s[0]=='0');
  for(int i=1;i<n;i++){
    acc1[i]=acc1[i-1]+(s[i]=='1');
    acc0[i]=acc0[i-1]+(s[i]=='0');
  }
  bool flag=1;
  if(acc1[n-1]!=acc0[n-1]){
    flag=0;
  }
  int idx=-1;
  if(flag)
  for(int i=0;i<n;i++){
    if(acc1[i]!=acc0[i] && acc1[n-1]-acc1[i]!=acc0[n-1]-acc0[i]){
      idx=i;break;
    }
  }
//  cout<<idx<<" indice\n";
  if(idx==-1){
    cout<<1<<"\n"<<s<<"\n";
    return 0;
  }
  cout<<2<<"\n";
  for(int i=0;i<=idx &&i<n;i++)
    cout<<s[i];
    cout<<" ";
  for(int i=idx+1;i<n;i++)
    cout<<s[i];
    cout<<"\n";
  return 0;
}
