#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
const int N =100005;
int v[N];
int main()
{
  v[0]=v[1]=0;
  for(int i=2;i*i<N;i++)
    if(!v[i])
      for(int j=i*i;j<N;j+=i)
        v[j]=1;
  int n;
  cin>>n;
  if(n==1){
    cout<<"1\n1\n";
    return 0;
  }
  if(n==2){
    cout<<"1\n1 1\n";
    return 0;
  }
  cout<<2<<endl;
  for(int i=2;i<=n+1;i++)
    cout<<v[i]+1<<" ";
  return 0;
}
