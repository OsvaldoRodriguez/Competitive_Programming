#include <bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin >> n;
    string ans = "NO";
    if(n > 2 && n % 2 == 0)
        ans = "YES";
    cout << ans << '\n';
    return 0;
}
