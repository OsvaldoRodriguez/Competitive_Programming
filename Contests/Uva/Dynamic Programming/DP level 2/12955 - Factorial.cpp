#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 550;
const ll mod = 1e9 + 7;
int fact[10];
int n;
int dp[500000];

int f(int u){
    if(u < 0)
        return 1e9;
    if(u == 0)
        return 0;
    int &ans = dp[u];
    if(ans != -1)
        return ans;

    ans = 1e9;
    for(int i = 0; i < 10; i++)
        ans = min(ans, f(u - fact[i]) + 1);
    return ans;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i < 11; i++)
        fact[i] = fact[i - 1] * i;
    memset(dp, -1, sizeof dp);
    while(cin >> n){
        cout << f(n) << '\n';
    }
    return 0;

}
