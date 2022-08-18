#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e2 + 100;
const ll mod = 1e9 + 7;

int coin[N];
int n;
int dp[100010][N];
int f(int value, int pos){
    if(value < 0)
        return 0;
    if(pos == n)
        return value == 0;
    int &ans = dp[value][pos];
    if(ans == -1){
        ans = 0;
        ans |= f(value - coin[pos], pos + 1);
        ans |= f(value, pos + 1);
    }
    return ans;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> coin[i];
    memset(dp, -1, sizeof dp);

    vector<int> ans;
    for(int i = 1; i <= 100000; i++){
        if(f(i, 0))
            ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i + 1 < ans.size())
            cout << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++)
        solve();
    return 0;
}
