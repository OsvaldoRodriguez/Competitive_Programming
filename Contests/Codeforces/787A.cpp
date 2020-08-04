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
  bool flag=0;
  int a,b,c,d;
  while(cin>>a>>b>>c>>d){
    flag=0;
    for(int i=0;i<1000;i++){
      int j=(a*i+b-d)/c;
      //cout<<a*i+b<<" "<<c*j+d<<endl;
      if(a*i+b==c*j+d && j>=0)
      {
        flag=1;
        cout<<c*j+d<<endl;
        break;
      }
    }
    if(!flag)
      cout<<-1<<endl;
  }

  return 0;
}
