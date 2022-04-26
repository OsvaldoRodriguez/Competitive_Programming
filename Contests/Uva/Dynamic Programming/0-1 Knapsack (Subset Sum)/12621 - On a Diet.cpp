#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3 + 550;
const ll mod = 1e9 + 7;
int n, W;
int A[N];
ll dp[N][2 * 320];

ll f(int i, int w){
    if(i == n)
        return (w >= W ? 0 : 1e9);
    ll &ans = dp[i][w];
    if(ans == -1){
        ans = 1e9;
        if(w + A[i] <= 500)
            ans = min(ans, f(i + 1, w + A[i]) + A[i]);
        ans = min({ans, f(i + 1, w)});
    }
    return ans;
}
int main(){

    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &W, &n);
        W /= 10;
        for(int i = 0; i < n; i++){
            cin >> A[i];
            A[i] /= 10;
        }

        for(int i = n; i >= 0; i--){
            for(int w = 250; w >= 0; w--){
                ll &ans = dp[i][w];
                if(i == n){
                    ans = (w >= W ? 0 : 1e9);
                }else{
                    ans = 1e9;
                    if(w + A[i] <= 500)
                        ans = min(ans, dp[i + 1][w + A[i]] + A[i]);
                    ans = min(ans, dp[i + 1][w]);
                }
                
            }
        }
        ll ans = dp[0][0];
        if(ans == 1e9)
            printf("NO SOLUTION\n");
        else
            printf("%d\n", ans * 10);
    }
    return 0;

}
