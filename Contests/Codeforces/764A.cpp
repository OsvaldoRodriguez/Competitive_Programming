#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1000001;
int GCD(int a,int b){
  if(!b)return a;
  return GCD(b,a%b);
}
int LCM(int a,int b){
  return a*(b/GCD(a,b));
}
int main()
{
  int n,m,z,l;
  while(cin>>n>>m>>z)
    cout<<z/LCM(n,m)<<endl;

  return 0;
}
