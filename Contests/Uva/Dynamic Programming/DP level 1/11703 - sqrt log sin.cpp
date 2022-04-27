#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 550;
const ll mod = 1e9 + 7;
ll dp[N];
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[0] = 1;
    for(int i = 1; i < N; i++){
        int a = floor(i - sqrt(i));
        int b = floor(log(i));
        int c = floor(i * sin(i) * sin(i));
        dp[i] = (dp[a] + dp[b] + dp[c]) % 1000000;
    }
    int n;
    while(cin >> n and n != -1){
        cout << dp[n] << '\n';
    }
    return 0;

}
