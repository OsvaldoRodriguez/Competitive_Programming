#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000010;
ll v[N];
int main()
{
  int n;
  ll c=2,h=2;
  v[4]=1;
  for(int i=5;i<N;i++){
    v[i]=v[i-1]+c;
    c+=h;
    if((i&1)==0)
      h++;
  }/*
  for(int i=100000;i<100100;i++){
    cout<<i<<" "<<v[i]<<endl;
  }*/
  while(cin>>n && n>=3)
    cout<<v[n]<<'\n';
}
