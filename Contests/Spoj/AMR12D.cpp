#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 20005;
int main()
{
  int t;
  string c;
  cin>>t;
  while(t--){
    cin>>c;
    string cc=c;
    reverse(cc.begin(),cc.end());
    if(cc==c)
      cout<<"YES\n";
    else
      cout<<"NO\n";
 
  }
  return 0;
}
