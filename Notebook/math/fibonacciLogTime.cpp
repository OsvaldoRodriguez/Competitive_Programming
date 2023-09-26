#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fibo(int n){
  ll a, b, x, y, tmp;
  a = x = tmp = 0;
  b = y = 1;
  while(n != 0){
    if(!(n % 2)){
      tmp = a * a + b * b;
      b = b * a + a * b + b * b;
      a = tmp;
      n = n / 2;
    }
    else{
      tmp = a * x + b * y;
      y = b * x + a * y + b * y;
      x = tmp;
      n = n - 1;
    }
  }
  return y;
}
int main(){
  ll n;
  cin >> n;
  cout << fibo(n) << '\n';
}
