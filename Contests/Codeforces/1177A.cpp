#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 1e5+10;
int main(){
  string a="";
  for(int i=1;i<=10000;i++)
    a+=to_string(i);
  int n;
  cin>>n;
  cout<<a[n-1]<<"\n";
  return 0;
}
