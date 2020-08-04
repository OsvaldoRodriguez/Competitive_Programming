#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 1000;
bool palin(string s){
  for(int i =0;i<s.size();i++)
    if(s[i]!=s[(int)s.size()-i-1])
      return 0;
  return 1;
}
bool vocal(string s){
  for(auto i:s){
    if(i!='A' && i!='H' && i!='I' && i!='M' && i!='O' && i!='T' && i!='U' && i!='V' && i!='W' && i!='X' &&i!='Y')
      return 0;
  }
  return 1;
}
int main(){
  int t;
  cin>>t;
  string s;
  while(t--){
    cin>>s;
    if(vocal(s) && palin(s))
      cout<<"yes\n";
    else cout<<"no\n";
  }
  return 0;
}
