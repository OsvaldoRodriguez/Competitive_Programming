#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =100005;
int main(){
  int n,t;
  string s;
  while(cin>>n>>t){
    cin>>s;
    while(t--){
      for(int i=1;i<s.size();i++)
        if(s[i]=='G' && s[i-1]=='B'){
          swap(s[i],s[i-1]);
            i++;
        }
    }
    cout<<s<<endl;
  }
  return 0;
}
