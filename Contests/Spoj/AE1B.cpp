#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1001;
int v[N];
bool cmp(int a,int b){
  return a>b;
}
int main()
{
  int n,k,s;
  while(cin>>n>>k>>s){
    for(int i=0;i<n;i++)
      cin>>v[i];
    sort(v,v+n,cmp);
    int i=0;
    int ans=0;
    while(k*s>ans && i<n){
      ans+=v[i];
      i++;
    }
    cout<<i<<endl;
  }
 
 
 
  return 0;
}
