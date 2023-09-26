#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int v[N], sol[N];
int n;
void solucion(){
  stack<int> s;
  for(int i = 0; i < n; i++){
    while(!s.empty() && s.top() >= v[i])
      s.pop();
    if(s.empty()){
      sol[i] = -1;
    }
    else{
      sol[i] = s.top();
    }
    s.push(v[i]);
  }
}
int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> v[i];
  solucion();
  for(int i = 0; i < n; i++)
    cout << sol[i] << " ";
  return 0;
}
