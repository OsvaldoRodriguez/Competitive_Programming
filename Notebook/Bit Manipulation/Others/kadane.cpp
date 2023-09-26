#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int v[n];
  for(int i = 0; i < n; i++)
    cin >> v[i];
    int p = 0, s = 0;
    for(int i = 0; i < n; i++){
        s = max(v[i], s + v[i]);
        p = max(s, p);
    }

    cout << p << "\n";
}
