#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 550;
const ll mod = 1e9 + 7;
int n;
int A[N];
int dp[N][N];

int f(int i, int u){
    if(u < 0)
        return 1e9;
    if(i == n)
        return u == 0 ? 0 : 1e9;
    int &ans = dp[i][u];
    if(ans == -1){
        ans = 1e9;
        ans = min(ans, f(i + 1, u - A[i]) + 1);
        ans = min(ans, f(i + 1, u));
    }
    return ans;

}
int main(){

    int t;
    scanf("%d", &t);
    while(t--){
        int money;
        scanf("%d", &money);
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", A + i);
        memset(dp, -1, sizeof dp);
        int ans = -1, cantidad = -1;
        for(int j = money; j <= 20000; j++){
            int cur = f(0, j);
            if(cur != 1e9){
                ans = j;
                cantidad = cur;
                break;
            }
        }
        printf("%d %d\n", ans, cantidad);
        // cout << ans << " " << cantidad << '\n';
    }
    return 0;

}
