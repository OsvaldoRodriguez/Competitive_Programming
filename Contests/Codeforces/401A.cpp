#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 100005;
map<char,string> m;
int main()
{
  int n,x,y,t;
  while(cin>>n>>x){
    int ans=0;
    t=0;
    while(n--){
      cin>>y;ans+=y;
    }
    ans=abs(ans);
    t=ans/x;
    if(ans%x!=0)
      t++;
    cout<<t<<endl;
  }
  return 0;
}
