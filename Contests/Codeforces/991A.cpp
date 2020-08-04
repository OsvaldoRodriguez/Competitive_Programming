#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,c,count;
  cin>>a>>b>>c>>count;
  for (int i = 0; i <= count; i++) {
    for (int j = 0; j <= count; j++) {
      for (int k = 1; k <= count; k++) {
        if(i+c==a and j+c==b and i+j+k+c == count){
          cout<<k;
          return 0;
        }
      }
    }
  }
  cout<<-1;
  return 0;
}
