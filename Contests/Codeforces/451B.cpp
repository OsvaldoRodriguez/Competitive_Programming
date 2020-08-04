#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =100005;
int v[N];
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>v[i];
  int i=0,pi=-1,pf=-1;bool flag=1;
  for(int i=0;i<n-1;i++){
    if(v[i]>v[i+1]){
      if(flag){
        flag=0;
        pi=i;
      }
    }
    else{
      if(!flag){
        pf=i;
        break;
      }
    }
  }
  if(pi!=-1 && pf==-1)
    pf=n-1;
  int j=0;
  if(pi!=-1 && pf!=-1)
    for(int i=pi;i<=(pf+pi)/2;i++)
      swap(v[i],v[pf-j++]);
  flag=1;
  for(int i=1;i<n;i++)
    if(v[i]<v[i-1]){
      flag=0;
      break;
    }
  if(flag){
    cout<<"yes\n";
    if(pi==-1 && pf==-1)
      cout<<"1 1\n";
    else cout<<++pi<<" "<<++pf<<"\n";
  }
  else
  cout<<"no\n";
  return 0;
}
