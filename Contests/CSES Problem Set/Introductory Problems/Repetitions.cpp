#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    int n = str.size();
    int cur = 0;
    int ans = 0;
    char last = str[0];
    for(int i = 0; i < n; i++){
        if(last == str[i])
            cur++;
        else{
            ans = max(ans, cur);
            cur = 1;
        }
        last = str[i];
    }
    ans = max(ans, cur);
    cout << ans << '\n';
    return 0;
}
