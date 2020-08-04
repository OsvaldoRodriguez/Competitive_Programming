#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =1000001;
int main(){
  string s;
  while(cin>>s){
    bool flag=0;
    int pos=-1,p;
    int im=s[s.size()-1]-'0';
    for(int i=0;i<s.size()-1;i++){
      int par=s[i]-'0';
      if(!(par&1)){
        flag=1;
        if(im>par){
          pos=i;
          break;
        }
        p=i;
      }
    }
    if(flag){
      if(pos!=-1)
        swap(s[pos],s[s.size()-1]);
      else
        swap(s[p],s[s.size()-1]);
      cout<<s<<endl;
    }else cout<<-1<<"\n";
  }
  return 0;
}
