#include <bits/stdc++.h>
 
using namespace std;
const int N = 1e6 + 100;
 
int coin[110]; 
int dp[N];
 
int main(){
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
        cin >> coin[i];
 
    for(int i = 0; i < x + 1; i++)
        dp[i] = 1e9;
 
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i >= coin[j])
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
        }
    }
    int ans = dp[x];
    if(ans == 1e9)
        ans = -1;
 
    cout << ans << '\n';
    return 0;
}
