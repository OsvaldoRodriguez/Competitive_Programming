#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> il;
typedef pair<ll,int> li;
const int N = 90;
int v[N];
int main(){
  int n;
  for(int i=1;i<N;i++)
    v[i]=v[i-1]+i;
  for(int i=2;i<N;i++)
    v[i]=v[i-1]+v[i];
  
  cin>>n;
  int i=1;
  for(;i<N;i++)
    if(v[i]>n)
      break;
    cout<<i-1<<"\n";

  return 0;
}
